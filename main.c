#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
	char nome[30];
	struct node *prox;
};
typedef struct node Node;

int tamanho;

void deleta(void);
void adiciona(Node**, int, char*);
void adiciona_fim(Node**, char*);
void list(Node**);

int
main(void) {

	Node *lista = NULL;
	char comando[50];
	char func[6];
	int pos;
	char nome[30];

	do {
		/* puts(	"\nadd [num] - Adiciona elemento\n"
				"addAt [pos] [nome]\n"
				"del [num] - remove um elemento\n"
				"delAt [pos] [nome]\n"
				"quit - deixar o programa\n"
				"Digite um comando:"); */

		fgets(comando, 50, stdin);

		sscanf(comando,"%s", func);

		if(strcmp(func, "addAt") == 0 )  {
			sscanf(comando, "%s%d%s", func, &pos, nome);
		}
		else if (strcmp(func, "delAt") == 0) {
			sscanf(comando, "%s%d", func, &pos);
		}
		else {
			sscanf(comando, "%s%s", func, nome);
		}

		if (strcmp(func, "add") == 0) {
			adiciona_fim(&lista, nome);
		}
		else if (strcmp(func, "addAt") == 0) {
			adiciona(&lista, pos, nome);
		}
		else if (strcmp(func, "del") == 0) {
			deleta();
		}
		else if (strcmp(func, "delAt") == 0) {
			deleta();
		}
		else if (strcmp(func, "lista") == 0) {
			list(&lista);
		}
		else{
			if(strcmp(func, "quit") != 0)
				puts("Comando inválido");
		}

	}while(strcmp(func, "quit") != 0);

	return 0;

}

void adiciona(Node **lista, int pos, char nome[30]) {
	
	Node *novo = (Node*) malloc(sizeof(Node));
	Node *atual = *lista;
	Node *ant = NULL;

	if(novo == NULL) {
		return;
	}
	strcpy(novo->nome, nome);
	novo->prox = NULL;

	if(*lista == NULL || pos == 1){
		Node *temp = *lista;
		*lista = novo;
		novo->prox = temp;
		return;
	}

	int i;
	for(i = 1; i < pos && atual != NULL; ++i ) {
		ant = atual;
		atual = atual->prox;
	}
	if(i != pos) {
		puts("Posicao invalida!");
		return;
	}
	ant->prox = novo;
	novo->prox = atual;
	
	return;
}

void adiciona_fim(Node **lista, char *nome) {
	Node *novo = (Node*) malloc(sizeof(Node));
	Node *atual = *lista;
	Node *ant = NULL;

	if(novo == NULL) {
		return;
	}
	strcpy(novo->nome, nome);
	novo->prox = NULL;

	if(*lista == NULL){
		*lista = novo;
		return;
	}

	while (atual != NULL) {
		ant = atual;
		atual = atual->prox;
	}
		ant->prox = novo;
		novo->prox = atual;
	
	return;
}

void deleta() {
	puts("Funcao remove invocada");
	return;
}

void list(Node **lista) {
	Node *atual = *lista;

	while (atual != NULL) {
		printf("%s -> ", atual->nome);
		atual = atual->prox;
	}
	puts("FIM");
}
