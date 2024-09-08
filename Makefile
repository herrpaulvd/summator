.PHONY: all clean check

all: summator
summator:
	gcc main.c -o summator
clean:
	rm -f summator
check:
	./testall.sh
