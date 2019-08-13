CC=g++
CXXFLAGS= -std=c++11 -g

OBJS = cambio.o main.o

all: ${OBJS}
	$(CXX) $(CXXFLAGS) -o prueba ${OBJS}

clean: 
	rm -r $(OBJ) $(BIN)