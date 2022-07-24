main:
	gcc cexception.c main.c -o main

run: main
	./main

clean:
	rm -f *.exe
	rm -f main
