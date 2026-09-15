#include <stdio.h>
#include <unistd.h>//Acesso à POSIX
#include <sys/wait.h>

int main(void) {

    pid_t pid = getpid();

    printf("PID: %d\n", pid);



 pid_t pid_novo = fork();//decorrente do PID original - pai

    if (pid_novo == 0) {//indicativo que está no processo novo (decorrente)

        printf("Novo PID - decorrente do PID inicial\n");

        printf("PID: %d\n", getpid());//Descobre o PID verdadeiro do filho (Processo decorrente)

        return 0;

    }

    waitpid(pid_novo, NULL, 0);//Espera acabar o processo novo

    printf("Processo finalizado.\n");

    return 0;
}