#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 10

typedef struct Pessoa
{
    char nome[MAX_NAME_LEN];
    int idade;
    char telefone[30];
    struct Pessoa *prox;
} Pessoa;

void incluir(Pessoa **pBuffer)
{
    Pessoa *nova = malloc(sizeof(Pessoa));
    printf("Digite o nome (até %d caracteres): ", MAX_NAME_LEN - 1);
    scanf("%s", nova->nome);
    printf("Digite a idade: ");
    scanf("%d", &nova->idade);
    printf("Digite o telefone: ");
    scanf("%s", nova->telefone);
    nova->prox = *pBuffer;
    *pBuffer = nova;
}

void apagar(Pessoa **pBuffer)
{
    char nome[MAX_NAME_LEN];
    Pessoa *ant = NULL, *atual = *pBuffer;
    printf("Digite o nome da pessoa que deseja apagar: ");
    scanf("%s", nome);
    while (atual != NULL && strcmp(atual->nome, nome) != 0)
    {
        ant = atual;
        atual = atual->prox;
    }
    if (atual == NULL)
    {
        printf("Pessoa não encontrada.\n");
        return;
    }
    if (ant == NULL)
    {
        *pBuffer = atual->prox;
    }
    else
    {
        ant->prox = atual->prox;
    }
    free(atual);
}

void buscar(Pessoa *pBuffer)
{
    char nome[MAX_NAME_LEN];
    printf("Digite o nome da pessoa que deseja buscar: ");
    scanf("%s", nome);
    while (pBuffer != NULL && strcmp(pBuffer->nome, nome) != 0)
    {
        pBuffer = pBuffer->prox;
    }
    if (pBuffer == NULL)
    {
        printf("Pessoa não encontrada.\n");
        return;
    }
    printf("Nome: %s, Idade: %d, Telefone: %s\n",
           pBuffer->nome, pBuffer->idade, pBuffer->telefone);
}

void listar(Pessoa *pBuffer)
{
    printf("Lista de pessoas:\n");
    while (pBuffer != NULL)
    {
        printf("Nome: %s, Idade: %d, Telefone: %s\n",
               pBuffer->nome, pBuffer->idade, pBuffer->telefone);
        pBuffer = pBuffer->prox;
    }
}

int main()
{
    Pessoa *pBuffer = NULL;
    int opcao;
    do
    {
        printf("Escolha uma opção:\n");
        printf("1. Incluir\n");
        printf("2. Apagar\n");
        printf("3. Buscar\n");
        printf("4. Listar\n");
        printf("5. Sair\n");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            incluir(&pBuffer);
            break;
        case 2:
            apagar(&pBuffer);
            break;
        case 3:
            buscar(pBuffer);
            break;
        case 4:
            listar(pBuffer);
            break;
        case 5:
            break;
        default:
            printf("Opção inválida.\n");
        }
    } while (opcao != 6);
}
