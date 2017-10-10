#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char *argv[])
{
    int i, pid,pid1,pid2,pid3,pid4,count;
    int status;
    if(argc!=3) {
        printf("incorrect number of arguments \n");
        exit(EXIT_FAILURE);
    }

    int A,B,S,rem;
    count=0;
    S=0;
    A=atoi(argv[1]);
    B=atoi(argv[2]);
    printf("%d,\t %d\n", A, B);
    //////////////////

    pid1 = fork();
    if (pid1 == 0)
    {   
        pid=getpid();
        printf("Forked child %d \n", pid);
        S=A+B;
        printf("I am child number %d, the sum is %d \n", 1, S);
        exit(EXIT_SUCCESS);
    }
    else if (pid1 < 0)
    {
        printf("Fork error %d.\n", errno);
        exit(EXIT_FAILURE);
    }

    pid2 = fork();
    if (pid2 == 0)
    {   
        pid=getpid();
        printf("Forked child %d \n", pid);        
        S=A-B;
        printf("I am child number %d, the difference is %d \n", 2, S);
        exit(EXIT_SUCCESS);
    }
    else if (pid2 < 0)
    {
        printf("Fork error %d.\n", errno);
        exit(EXIT_FAILURE);
    }

    pid3 = fork();
    if (pid3 == 0)
    {   
        pid=getpid();
        printf("Forked child %d \n", pid);
        S=A*B;
        printf("I am child number %d, the product is %d \n", 3, S);
        exit(EXIT_SUCCESS);
    }
    else if (pid3 < 0)
    {
        printf("Fork error %d.\n", errno);
        exit(EXIT_FAILURE);
    }

    pid4 = fork();
    if (pid4 == 0)
    {   
        pid=getpid();
        printf("Forked child %d \n", pid);
        S=A/B;
        rem=A%B;
        printf("I am child number %d, the quotient is %d and the remainder is %d \n", 4, S, rem);
        exit(EXIT_SUCCESS);
    }
    else if (pid4 < 0)
    {
        printf("Fork error %d.\n", errno);
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < 3; ++i)
    {
        wait(&status);
    }

    printf("i am done waiting \n");
    exit(EXIT_SUCCESS);
}