all: rom_merge.c rom_split.c
	gcc -Werror rom_merge.c -o rom_merge
	gcc -Werror rom_split.c -o rom_split

clean:
	rm -rf rom_merge
	rm -rf rom_split

