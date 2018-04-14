FILES=main.cpp LongInt.cpp
APP_NAME=LongInt
OPTIMIZE_LEVEL=3
FLAGS=-Wall -Wunreachable-code -pedantic

all:
	g++ $(FLAGS) -O$(OPTIMIZE_LEVEL) $(FILES) -o $(APP_NAME)

clean:
	rm -rf $(APP_NAME)