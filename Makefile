
OBJS = main.o Player.o
SOURCE = main.cpp Player.cpp
HEADER = BlackCard.hpp GreenCard.hpp main.hpp Player.hpp
OUT = main
CC = g++
FLAGS = -c

$(OUT): $(OBJS)
		$(CC) $(OBJS) -o $@

main.o: main.cpp
		  $(CC) $(FLAGS) main.cpp

Player.o: Player.cpp
		 $(CC) $(FLAGS) Player.cpp

clean:
		rm -f ($OBJS) $(OUT)

count:
	wc $(SOURCE) $(HEADER)
