#include <stdio.h>
#include <string.h>


int main (void){
    escrita();
    leitura();
    renomear();
    deletar();
}





int escrita () {
    FILE *arquivo = fopen("exemplo.txt", "w");
    if (arquivo == NULL){
        printf("Erro ao criar o arquivo\n");
        return 1;
    }
    fprintf(arquivo, "teste de escrita e leitura com arquivos\n");
    fprintf(arquivo, "teste finalizado");

    fclose(arquivo);

    return 0;
}

int leitura(){
    FILE *arquivo = fopen("exemplo.txt", "r");
    if (arquivo == NULL){
        printf("Erro ao abrir o arquivo");
        return 1;
    }

    char linha[256];

    while(fgets(linha, sizeof(linha), arquivo) != NULL){
        printf("%s", linha);
    }

    fclose(arquivo);

    return 0;
}

int renomear(){
    if(rename("exemplo.txt", "exemplo2.txt") !=0){
        printf("Erro ao renomear arquivo. \n");
        return 1;
    }

    printf("Arquivo renomeado!\n");
    return 0;
}

int deletar(){
    if(remove("exemplo.txt") !=0){
        printf("Erro ao deletar arquivo.\n");
        return 1;
    }

    printf("Aquivo deletado\n");
    return 0;
}
