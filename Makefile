
all: main

CC = gcc
CFLAGS = -std=c11 -Werror -Wall -Wextra -pedantic

.PHONY: all run clean

main: main.c
	$(CC) $(CFLAGS) $^ -o "$@"

run: main
	./main

clean:
	rm main

git:
	git add main.c
	- git commit -m "Update main.c"
	- git pull origin main --rebase
	git push origin main