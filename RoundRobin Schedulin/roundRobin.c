#include<stdio.h>

struct p {
    int pid;
    int bt;
    int wt;
    int tat;
    int rem_bt;
};

int main(){
    int num_process;

    printf("Enter the number of processes:");
    scanf("%d",&num_process);

    struct p process[num_process];

    for(int i=0;i<num_process;i++){
        printf("Enter the process ID, and burst time of process %d: ",i+1);
        scanf("%d %d",&process[i].pid,&process[i].bt);
        process[i].rem_bt = process[i].bt;
    }

    int quantum;
    printf("Enter the quantum time of the processes:");
    scanf("%d",&quantum);

    int total_remaining_time = 0;

    for(int i=0;i<num_process;i++){
        total_remaining_time += process[i].bt;
    }

    int time = 0;

    while(total_remaining_time > 0){
        for(int i=0;i<num_process;i++){
            if(process[i].rem_bt > 0){
                if(process[i].rem_bt > quantum){
                    total_remaining_time -= quantum;
                    time += quantum;
                    process[i].rem_bt -= quantum;
                }
                else{
                    total_remaining_time -= process[i].rem_bt;
                    time += process[i].rem_bt;
                    process[i].wt = time - process[i].bt; 
                    process[i].rem_bt = 0;
                    process[i].tat = time; 
                }
            }
        }
    }

    //Calculating the average waiting time and average turn around time...

    float total_wt=0;
    float total_tat=0;

    for(int i=0;i<num_process;i++){
        total_wt += process[i].wt;
        total_tat += process[i].tat;
    }

    float avg_wt = total_wt/num_process;
    float avg_tat = total_tat/num_process;

    printf("Process ID\t Burst Time\t Waiting Time\t Turnaround Time\n");
    for(int i=0;i<num_process;i++){
        printf("\t%d\t \t%d\t \t%d\t \t%d\t\n",process[i].pid,process[i].bt,process[i].wt, process[i].tat);
    }

    printf("The average waiting time is %f\n", avg_wt);
    printf("The average turn around time is %f\n", avg_tat);

    return 0;
}
