#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <pthread.h>
#include <math.h>
#define timespec j;
#include <sched.h>
int main(void){
    pid_t id_1,id_2,id_3;
    struct j begin_1,end_1;
    clock_gettime(CLOCK_REALTIME,&begin1);
    int zero = 0;
    id_1=fork();
    if(!(id_1!=zero)){
        struct sched_param priority_1;
        priority_1.sched_priority = 0;
        sched_setscheduler(0,SCHED_OTHER,&priority_1);
        execl("/bin/bash","sh","kernel.sh",NULL);
    }

    else{
        wait(NULL);
        clock_gettime(CLOCK_REALTIME,&end_1);
        double t1 = (((end_1.tv_sec - begin_1.tv_sec) * 1000000000) + (end_1.tv_nsec - begin_1.tv_nsec)) /1000000000.0;
        printf("Time for Process-1:%lf\n",t1);
        struct timespec begin_2,end_2;
        clock_gettime(CLOCK_REALTIME,&begin_2);
        int nzero=0;
        id_2 = fork();  
        if(!(id_2!=nzero)){
            struct sched_param priority_2;
            priority_2.sched_priority=10;
            sched_setscheduler(0,SCHED_OTHER,&priority_2);
            execl("/bin/bash","sh","kernel.sh",NULL);

        }
        else{
            wait(NULL);
            clock_gettime(CLOCK_REALTIME,&end_2);
            double t2 = (((end_1.tv_sec - begin_1.tv_sec) * 1000000000) + (end_1.tv_nsec - begin_1.tv_nsec)) /1000000000.0;
            printf("Time for Process-2:%lf\n",t2);
            struct j end_3,begin_3;
            clock_gettime(CLOCK-REALTIME,&begin_3);
            int zero2=0;
            id_3=fork();
            if(!(id_3!=zero2)){
                struct sched_param priority_3;
                priority_3.sched_priority=20;
                sched_setscheduler(0,SCHED_OTHER,&priority_3);
                execl("/bin/bash","sh","kernel.sh",NULL);

            }
            else{
                wait(NULL);
                clock_gettime(CLOCK_REALTIME,&end_2);
                double t3 = (((end_1.tv_sec - begin_1.tv_sec) * 1000000000) + (end_1.tv_nsec - begin_1.tv_nsec)) /1000000000.0;
                printf("Time for Process-3:%lf\n",t3);
            }
        }
    
    }   
}



