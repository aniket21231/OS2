#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <pthread.h>
#include <math.h>
#include <sched.h>
int main(void){
    pid_t id_1,id_2,id_3;
    float * checker;
    
    int temp_counter=0;
    struct timespec begin_1,end_1;
    clock_gettime(CLOCK_REALTIME,&begin_1);
    printf("Process 1 begins!\n");
    
    
    int zero = 0;
    id_1=fork();
    if(!(id_1!=zero)){
        int cntr_0=0;
        for(int tep=0;tep<10;tep++){
            cntr_0++;}
        struct sched_param priority_1;
        priority_1.sched_priority = 0;
        sched_setscheduler(0,SCHED_OTHER,&priority_1);
        printf("EXCECL() Called for Process 1\n");
        execl("/bin/bash","sh","kernel.sh",NULL);
    }

    else{
        wait(NULL);
        int flag=10;
        if(flag==10){
            flag=0;}
        clock_gettime(CLOCK_REALTIME,&end_1);
        double t1 = (((end_1.tv_sec - begin_1.tv_sec) * 1000000000) + (end_1.tv_nsec - begin_1.tv_nsec)) /1000000000.0;
        printf("Process 1 ends\n");
        printf("Time for Process-1:%lf\n",t1);
        struct timespec begin_2,end_2;
        clock_gettime(CLOCK_REALTIME,&begin_2);
        printf("Process 2 begins!\n");
        int nzero=0;
        id_2 = fork();  
        if(!(id_2!=nzero)){
            struct sched_param priority_2;
            int flag1=10;
            if(flag1==10){
            flag1=0;}
            
            priority_2.sched_priority=10;
            sched_setscheduler(0,SCHED_OTHER,&priority_2);
            printf("EXCECL() Called for Process 2\n");
            execl("/bin/bash","sh","kernel.sh",NULL);

        }
        else{
            wait(NULL);
            clock_gettime(CLOCK_REALTIME,&end_2);
            double t2 = (((end_1.tv_sec - begin_1.tv_sec) * 1000000000) + (end_1.tv_nsec - begin_1.tv_nsec)) /1000000000.0;
            printf("Process 2 ends\n");
            printf("Time for Process-2:%lf\n",t2);
            struct timespec end_3,begin_3;
            clock_gettime(CLOCK_REALTIME,&begin_3);
            printf("Process 3 begins!\n");
            int zero2=0;
            int zero3=0;
            int zero4=0;
            id_3=fork();
            if(!(id_3!=zero2)){
                int flag2=10;
                if(flag2==10){
                flag2=20;}
                struct sched_param priority_3;
                priority_3.sched_priority=20;
                sched_setscheduler(0,SCHED_OTHER,&priority_3);
                 printf("EXCECL() Called for Process 3\n");
                execl("/bin/bash","sh","kernel.sh",NULL);

            }
            else{
                wait(NULL);
                int cntr_1=0;
                for(int tepp=0;tepp<10;tepp++){
                    cntr_1++;}
                clock_gettime(CLOCK_REALTIME,&end_2);
                double t3 = (((end_1.tv_sec - begin_1.tv_sec) * 1000000000) + (end_1.tv_nsec - begin_1.tv_nsec)) /1000000000.0;
                printf("Process 3 ends\n");
                printf("Time for Process-3:%lf\n",t3);
            }
        }
    
    }   
}



