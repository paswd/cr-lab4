FLAGS=-pedantic -Wall -Werror -Wno-sign-compare -Wno-long-long -lm -std=c++11 -O2
COMPILLER=g++

all: start

start: main.cpp variantgen.cpp
	$(COMPILLER) $(FLAGS) -o check main.cpp
	$(COMPILLER) $(FLAGS) -o variantgen variantgen.cpp



clean:
	@-rm -f *.o *.gch *.dat check variantgen
	@echo "Clean success"
