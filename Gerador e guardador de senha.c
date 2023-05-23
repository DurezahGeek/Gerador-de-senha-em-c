#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO_MAXIMO 10
#define CARACTERES_POSSIVEIS 94
#define CARACTERE_INICIAL 33

void salvarSenha(const char* senha) {
    FILE* arquivo = fopen("senhas.txt", "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    fprintf(arquivo, "%s\n", senha);
    fclose(arquivo);
}

int main() {
    int i;
    char senha[TAMANHO_MAXIMO + 1];

    srand(time(NULL));


    for (i = 0; i < TAMANHO_MAXIMO; i++) {
        senha[i] = (char)(rand() % CARACTERES_POSSIVEIS + CARACTERE_INICIAL);
    }
    senha[i] = '\0';

    printf("Senha gerada aleatória : %s\n", senha);

    salvarSenha(senha);

    return 0;
}
