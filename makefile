CC=g++ 

CFLAGS= -c -g -Wall -std=c++17 -fpermissive
EXENAME= Topograph

default: main.o lodepng.o picture.o Topograph.o 
	$(CC) main.o Topograph.o picture.o lodepng.o -o $(EXENAME)

main.o: main.cpp Topograph.h lodepng.h picture.h
	$(CC) $(CFLAGS) main.cpp 

Topograph.o: Topograph.cpp Topograph.h
	$(CC) $(CFLAGS) Topograph.cpp

picture.o: picture.cpp picture.h
	$(CC) $(CFLAGS) picture.cpp 

lodepng.o: lodepng.cpp lodepng.h
	$(CC) $(CFLAGS) lodepng.cpp

clean: 
	rm *.o $(EXENAME)

run:
    ./$(EXENAME)