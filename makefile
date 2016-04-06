all:main.c
	gcc -E main.c -o output.i
	gcc -S main.c -o output.asm
	gcc -C main.c -o output.obj
	gcc -O main.c -o output.exe
	
preprocessor: main.c
	gcc -E main.c -o output.i
