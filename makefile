SRC = main.cpp 
TARGET = programm.exe
LIB = mylib
HEADER_1 = message
HEADER_2 = user

programm: $(SRC) lib
	g++ -o $(TARGET) $(SRC) -L. -l$(LIB)

lib: $(HEADER_1).cpp $(HEADER_2).cpp
	g++ -o $(HEADER_1).o $(HEADER_1).cpp -c
	g++ -o $(HEADER_2).o $(HEADER_2).cpp -c
	ar rc lib$(LIB).a $(HEADER_1).o $(HEADER_2).o

clean:
	rm -rf *.o *.a

all: programm clean