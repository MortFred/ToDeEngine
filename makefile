SRC_DIR = ./src
TEST_DIR = ./tests
IDIR = ./include
ODIR = $(SRC_DIR)/obj
LDIR =./lib

CC=clang++
CPPFLAGS=-I$(IDIR) -I$(IDIR)/util
LINKER_FLAFS=-lSDL2
LIBS=-lm

_DEPS = HelloCpputest.h 
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = HelloCpputest.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

# $(ODIR)/%.o: $(SRC_DIR)/%.cpp $(DEPS)
# 	$(CC) -c -o $@ $< $(CPPFLAGS)
# HelloCpputest.o: $(SRC_DIR)/HelloCpputest.cpp $(IDIR)/HelloCpputest.h
# 	$(CC) -c $(SRC_DIR)/HelloCpputest.cpp -o HelloCpputest.o $(CPPFLAGS)
main.o: 

test:
	make -C $(TEST_DIR)

test_clean:
	make -C $(TEST_DIR) clean

# HelloCpputest: HelloCpputest.o
# 	$(CC) HelloCpputest.o -o HelloCpputest $(CPPFLAGS) $(LIBS) 

all: test HelloCpputest

.PHONY: clean

clean: test_clean
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 