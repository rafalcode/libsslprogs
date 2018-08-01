#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<sys/stat.h>
#include <openssl/sha.h>

void prtusage(void)
{
	printf("Slurps in content of a text file and hashes the entire thing as a single string\n");
    printf("Needs a single argument, the name of the file.\n"); 
    return;
}

int main(int argc, char *argv[])
{
	if(argc == 1) {
		prtusage();
		exit(EXIT_FAILURE);
	}
	struct stat ifsta;
	if(stat(argv[1], &ifsta) == -1) {
		fprintf(stderr,"Can't stat input file %s", argv[1]);
		exit(EXIT_FAILURE);
	}
    
    printf("Size of input file is %zu.\n", ifsta.st_size); 

    // unfort both of these need to be unsigned for the SHA1() function.
    unsigned char *bf=calloc(ifsta.st_size, sizeof(unsigned char));
    unsigned char hashbf[SHA_DIGEST_LENGTH];

    FILE *finp=fopen(argv[1], "r");
    int ret=fread(bf, ifsta.st_size, sizeof(unsigned char), finp); 
    if(ret<1) {
        printf("Prob reading file\n"); 
		exit(EXIT_FAILURE);
    }
    fclose(finp);

    int i;

    SHA1(bf, ifsta.st_size, hashbf);

    printf("hash now contains the %i-byte SHA-1 hash:\n", SHA_DIGEST_LENGTH);
    for(i=0;i<SHA_DIGEST_LENGTH;++i) 
         printf("%x", hashbf[i]);
    printf("\n"); 
    free(bf);
    return 0;
}
