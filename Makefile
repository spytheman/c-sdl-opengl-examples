CFLAGS=-g
LDLIBS=-lSDL -lGL

all: triangle

triangle:

.PHONY: clean all

clean:
	rm -rf triangle