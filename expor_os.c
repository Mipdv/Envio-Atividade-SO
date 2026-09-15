#include <stdio.h>
#include <sys/utsname.h> 

int obter_informacoes_so();

int main (void){
    obter_informacoes_so();
    return 0;
}

int obter_informacoes_so() {
    struct utsname info_so; 


    if (uname(&info_so) == -1) {
        perror("Erro ao obter informações do sistema operacional");
        return 1;
    }

    printf("\n--- Informações do Sistema Operacional ---\n");
    printf("Nome do Sistema: %s\n", info_so.sysname);     
    printf("Nome do Nó (hostname): %s\n", info_so.nodename);    
    printf("Release do Sistema: %s\n", info_so.release);    
    printf("Versão do Sistema: %s\n", info_so.version);     
    printf("Arquitetura da Máquina: %s\n", info_so.machine); 
    printf("-----------------------------------------\n");

    return 0;
}