.PHONY: clean tests touch

all: tests

bubble.o: bubble.c
	gcc -c bubble.c

clean:
	rm -f *.o
	rm -f tests/test_bubble

tests:
	cd tests && $(MAKE)

touch:
	touch bubble.c
