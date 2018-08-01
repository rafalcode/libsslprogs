#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

int main(int argc, char *argv[])
{
    // The data to be hashed
    unsigned char data[] = "Hello, world!";
    size_t length = strlen(data);
    int i;

    unsigned char hash[SHA_DIGEST_LENGTH];

    SHA1(data, length, hash);

    printf("hash now contains the %i-byte SHA-1 hash:\n", SHA_DIGEST_LENGTH);
    for(i=0;i<SHA_DIGEST_LENGTH;++i) 
        printf("%x", hash[i]);
    printf("\n"); 
    return 0;
}
