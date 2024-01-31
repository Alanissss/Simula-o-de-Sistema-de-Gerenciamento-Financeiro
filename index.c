#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct {
    char descricao[100];
    float valor;
} Transacao;


typedef struct {
    float saldo;
    Transacao transacoes[100];
    int num_transacoes;
} Conta;


void adicionarTransacao(Conta *conta, const char *descricao, float valor) {
    if (conta->num_transacoes < 100) {
        Transacao novaTransacao;
        snprintf(novaTransacao.descricao, sizeof(novaTransacao.descricao), "%s", descricao);
        novaTransacao.valor = valor;

        conta->transacoes[conta->num_transacoes] = novaTransacao;
        conta->num_transacoes++;

        conta->saldo += valor;

        printf("Transação adicionada com sucesso!\n");
    } else {
        printf("Limite máximo de transações atingido.\n");
    }
}


void exibirRelatorio(Conta *conta) {
    printf("\nSaldo Atual: R$ %.2f\n", conta->saldo);
    printf("Histórico de Transações:\n");

    for (int i = 0; i < conta->num_transacoes; i++) {
        printf("[%d] %s: R$ %.2f\n", i + 1, conta->transacoes[i].descricao, conta->transacoes[i].valor);
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    Conta minhaConta = {0, {}, 0};
    int opcao;
    char descricao[100];
    float valor;

    do {
        printf("\n### Sistema de Gerenciamento Financeiro ###\n");
        printf("1. Adicionar Transação\n");
        printf("2. Exibir Relatório\n");
        printf("3. Sair\n");

        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite a descrição da transação: ");
                scanf(" %[^\n]s", descricao);
                printf("Digite o valor da transação: R$ ");
                scanf("%f", &valor);
                adicionarTransacao(&minhaConta, descricao, valor);
                break;

            case 2:
                exibirRelatorio(&minhaConta);
                break;

            case 3:
                printf("Saindo do programa. Até logo!\n");
                break;

            default:
                printf("Opção inválida. Tente novamente.\n");
        }

    } while (opcao != 3);

    return 0;
}
