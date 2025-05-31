parametrosCompilacao=-Wall #-Wshadow
nomePrograma=myht

all: $(nomePrograma)

$(nomePrograma): myht.o hash.o
	gcc -o $(nomePrograma) myht.o hash.o -lm $(parametrosCompilacao)

myht.o: myht.c
	gcc -c myht.c $(parametrosCompilacao)

hash.o: hash.h hash.c
	gcc -c hash.c $(parametrosCompilacao)

clean:
	rm -f *.o *.gch $(nomePrograma)