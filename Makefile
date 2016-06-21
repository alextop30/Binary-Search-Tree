CC = g++
CFLAGS = -Wall -g -std=c++11

all: binStree

binStree.o: binSTree.h binTree.h includes.h Node.h binary_search_tree.cc
	${CC} ${CFLAGS} -c binary_search_tree.cc

binStree: binStree.o
	${CC} ${CFLAGS} binary_search_tree.o -o binary_search_tree

clean:
	rm -rf *.o
	rm -rf binary_search_tree
