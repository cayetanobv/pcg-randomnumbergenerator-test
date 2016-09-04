TARGETS = pcg-rng-test

all: $(TARGETS)

clean:
	rm -f *.o $(TARGETS) pcg-c-basic/pcg_basic.o

pcg-rng-test: pcg-rng-test.o pcg-c-basic/pcg_basic.o
