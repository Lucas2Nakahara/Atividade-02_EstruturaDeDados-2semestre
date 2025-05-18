#include <stdio.h>
#include <stdbool.h>
#define TAMANHO 100

typedef struct {
    int dados[TAMANHO];
    int topo;
} Pilha;

bool isEmpty(Pilha *p) {
    return p->topo == -1;
}

void inicializar(Pilha *p) {
    p->topo = -1;
}

void push(Pilha *p, int dado) {
    if (p->topo == TAMANHO - 1) {
        printf("Pilha Cheia!\n");
        return;
    }
    p->topo++;
    p->dados[p->topo] = dado;
}

int pop(Pilha *p) {
    if (isEmpty(p)) {
        printf("Pilha Vazia!\n");
        return -1;
    }
    return p->dados[p->topo--];
}

int topo(Pilha *p) {
    if (isEmpty(p)) {
        printf("Pilha Vazia!\n");
        return -1;
    }
    return p->dados[p->topo];
}

void imprime_pilha(Pilha *p) {
    if (isEmpty(p)) {
        printf("Pilha Vazia\n");
        return;
    }
    for (int i = 0; i <= p->topo; i++) {
        printf("%d -> ", p->dados[i]);
    }
    printf("topo\n");
}

int main() {
    Pilha p;
    inicializar(&p);

    int opcao, valor;

    do {
        printf("\n--- MENU PILHA ---\n");
        printf("1. Empilhar (push)\n");
        printf("2. Desempilhar (pop)\n");
        printf("3. Mostrar topo\n");
        printf("4. Imprimir pilha\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("Digite um valor para empilhar: ");
                scanf("%d", &valor);
                push(&p, valor);
                break;
            case 2:
                valor = pop(&p);
                if (valor != -1) {
                    printf("Valor desempilhado: %d\n", valor);
                }
                break;
            case 3:
                valor = topo(&p);
                if (valor != -1) {
                    printf("Topo da pilha: %d\n", valor);
                }
                break;
            case 4:
                imprime_pilha(&p);
                break;
            case 5:
                printf("Encerrando programa...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }

    } while(opcao != 5);

    return 0;
}
