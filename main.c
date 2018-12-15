#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	char *nome;
	struct node *prox;
};
typedef struct node Node;

void deleta(void);
void adiciona(void);

int
main(void) {

	Node *lista = NULL;
	char comando[50];
	char func[6];
	int pos;
	char nome[30];

	do {
		puts(	"\nadd [num] - Adiciona elemento\n"
				"addAt [pos] [nome]\n"
				"del [num] - remove um elemento\n"
				"delAt [pos] [nome]\n"
				"quit - deixar o programa\n"
				"Digite um comando:");

		fgets(comando, 50, stdin);

		sscanf(comando,"%s", func);

		if(strcmp(func, "addAt") == 0 )  {
			sscanf(comando, "%s%d%s", func, &pos, nome);
			puts("Cheguei aqui");
		}
		else if (strcmp(func, "delAt") == 0) {
			sscanf(comando, "%s%d", func, pos);
		}
		else {
			sscanf(comando, "%s%s", func, nome);
		}

		puts(func);

		if (strcmp(func, "add") == 0) {
			adiciona();
		}
		else if (strcmp(func, "addAt") == 0) {
			adiciona();
		}
		else if (strcmp(func, "del") == 0) {
			deleta();
		}
		else if (strcmp(func, "delAt") == 0) {
			deleta();
		}
		else{
			if(strcmp(func, "quit") != 0)
				puts("Comando inválido");
		}

	}while(strcmp(func, "quit") != 0);

	return 0;

}

void adiciona(Node **Lista, int pos, char *nome) {
	
	Node *novo = (Node*) malloc(sizeof(Node));
	if(novo == NULL) {
		return 1;
	}
	novo->nome = nome;
	novo->prox = NULL;

	
	return;
}

void deleta() {
	puts("Funcao remove invocada");
	return;
}
