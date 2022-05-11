SRC_DIR = ./src
TEST_DIR = ./tests
IDIR = ./include
ODIR = $(SRC_DIR)/obj
LDIR =./lib

CC=c++
CPPFLAGS= -I$(IDIR) -I$(IDIR)/util -std=c++17 -stdlib=libc++
LINKER_FLAGS= -lSDL2 -lm

src/obj/main.o: src/main.cpp include/HelloCpputest.h include/HelloSDL.h
	$(CC) -c -o $@ src/main.cpp $(CPPFLAGS)

src/obj/HelloSDL.o: src/HelloSDL.cpp include/HelloSDL.h
	$(CC) -c -o $@ src/HelloSDL.cpp $(CPPFLAGS)

test:
	make -C $(TEST_DIR)

test_clean:
	make -C $(TEST_DIR) clean

ToDe: src/obj/main.o src/obj/HelloSDL.o
	$(CC) -o $@ $^ $(LINKER_FLAGS)

all: test ToDe

.PHONY: clean
clean: test_clean
	rm -f *.o $(ODIR)/*.o ToDe


# src = $(wildcard src/*.c)
# obj = $(src:.c=.o)
# dep = $(obj:.o=.d)

# -include $(dep)

# LDFLAGS = -lGL -lglut -lpng -lz -lm
# .PHONY: clean

# clean: test_clean
# 	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 
# _DEPS = HelloCpputest.h 
# DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

# _OBJ = HelloCpputest.o 
# OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

# main: main.o module1.o module2.o
#     g++ main.o module1.o module2.o -o main
# main: main.o module1.o module2.o
#     gcc $^ -o $@

# $(ODIR)/%.o: $(SRC_DIR)/%.cpp $(DEPS)
# 	$(CC) -c -o $@ $< $(CPPFLAGS)
# HelloCpputest.o: $(SRC_DIR)/HelloCpputest.cpp $(IDIR)/HelloCpputest.h
# 	$(CC) -c $(SRC_DIR)/HelloCpputest.cpp -o HelloCpputest.o $(CPPFLAGS)