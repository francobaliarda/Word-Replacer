COMPILER=gcc
OUTPUT_FILE=Word_Replacer
FILES=Word_Replacer.c
FLAGS=-Wall -pedantic -std=c99
all:
	$(COMPILER) -o $(OUTPUT_FILE) $(FILES) $(FLAGS)
