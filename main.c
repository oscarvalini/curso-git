#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void deleta(void);
void adiciona(void);

int
main(void) {

	char comando[4];
	puts(	"add - Adiciona elemento\n"
		"del - remove um elemento\n"
		"Digite um comando: ");
	fgets(comando, 4, stdin);

	if (strcmp(comando, "add") == 0) {
		adiciona();
	}
	else if (strcmp(comando, "del") == 0) {
		deleta();
	}
	else{
		puts("Comando inválido");
	}

	return 0;

}

void adiciona() {
	puts("Funcao adiciona invocada");
	return;
}

void deleta() {
	puts("Funcao remove invocada");
	return;
}
