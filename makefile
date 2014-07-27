# Makefile for dbalhero
CXX = g++
CPPFLAGS = -g -Wall -std=c++11

.PHONY: clean

default: dbalhero

all: dbalhero coin

dbalhero: dbalhero.o knapsack.o
	$(CXX) $(CPPFLAGS) -o $@ $^ 

coin: coin.o knapsack.o
	$(CXX) $(CPPFLAGS) -o $@ $^

dbalhero.o: dbalhero.cpp dbalhero.h knapsack.h

coin.o: coin.h knapsack.h

knapsack.o: knapsack.cpp knapsack.h

clean:
	rm dbalhero coin *.o 