TARGETS = pcg-rng-test pcg-rng-test_seed

all: $(TARGETS)

clean:
	rm -f *.o $(TARGETS) pcg-c-basic/pcg_basic.o

pcg-rng-test: pcg-rng-test.o pcg-c-basic/pcg_basic.o
pcg-rng-test_seed: pcg-rng-test_seed.o pcg-c-basic/pcg_basic.o
