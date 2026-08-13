all:
	gcc main.c Aluno.c -o programa.exe

run: all
	.\programa.exe

clean:
	del programa.exe
