CC=gcc
CFLAGS=-g -Wall

LIBS=-lssl -lcrypto
EXES=ex1 ex2 ex3 ex4 ex5

ex1: ex1.c
	${CC} ${CFLAGS} -o $@ $^ ${LIBS}

ex2: ex2.c
	${CC} ${CFLAGS} -o $@ $^ ${LIBS}

ex3: ex3.c
	${CC} ${CFLAGS} -o $@ $^ ${LIBS}

ex4: ex4.c
	${CC} ${CFLAGS} -o $@ $^ ${LIBS}

ex5: ex5.c
	${CC} ${CFLAGS} -o $@ $^ ${LIBS}

.PHONY: clean

clean:
	rm -f ${EXES}
