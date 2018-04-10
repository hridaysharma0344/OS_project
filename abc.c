#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct process{
	int name;//stores the process name as integer value 
	float burst_time;//the time the process will take in CPU
	float arrival_time;//the time when the process arrives into the queue
	float status;//tell the status of the process whether done or still not done
	//0 for 'in queue' and 1 for 'Done'
	float waiting_time;//the time proces waits to gets executed
	float turnAroundTime;//the total time taken from getting to ready queue to finnaly getting executed
	
};

void display(struct process proc[],int num){
	int i;
	printf("The input process details are as shown below\n");
	printf("Process\tBurst-time\tArrival-time\n");
	for(i=0;i<num;i++){
		printf("p%d\t%f\t%f\n",proc[i].name,proc[i].burst_time,proc[i].arrival_time);
		
	}
	printf("\n");
}

void sort(struct process proc[],int num){
	int i,j;//iterative variables
	struct process temp;//a temp variable od struct process type so swap the entire process all together
	for(i=0;i<num-1;i++)//selection sort 
    {
        for(j=i+1;j<num;j++)
        {
            if(proc[i].arrival_time>proc[j].arrival_time){
				//swap the process with lesser arrival time
                temp=proc[i];
                proc[i]=proc[j];
                proc[j]=temp;
			}
        }
    }
}

