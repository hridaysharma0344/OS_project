void schedule(struct process proc[],int num,int sum){
	int i,j;
	float f,avgWaitingTime=0,avgTurnaroundTime=0;
	sort(proc,num);//sort according to the process arrival time
	printf("\nProcess\tBurst Time\tArrival Time\tWaiting Time\tTurn-Around Time\n");
	for(f=proc[0].arrival_time;f<(float)sum;){
		float pr=-9999;//priority
		int nxt;//hold the the next process
		float temp;	
		for(i=0;i<num;i++){
			//checking if the process is already complete
			if(proc[i].arrival_time<=f && proc[i].status!=1){
				temp=(proc[i].burst_time + (f - proc[i].arrival_time)) / proc[i].burst_time;
				if(pr<temp){
					//if higher priority take it as next process
					pr=temp;
					nxt=i;
				}
			}
		}
		//modify time	
		f=proc[nxt].burst_time+f;
		//waiting time
		proc[nxt].waiting_time=f-(proc[nxt].arrival_time)-(proc[nxt].burst_time);
		//Turn around time
		proc[nxt].turnAroundTime=f-proc[nxt].arrival_time;
		//average waiting time
		avgWaitingTime+=proc[nxt].waiting_time;
		//average turn around time
		avgTurnaroundTime+=proc[nxt].turnAroundTime;
		//update status
		proc[nxt].status=1;
		
		printf("p%d\t%f\t%f",proc[nxt].name,proc[nxt].burst_time,proc[nxt].arrival_time);
		printf("\t%f\t%f\n",proc[nxt].waiting_time,proc[nxt].turnAroundTime);
		
	}
	printf("Average waiting time=%f\n",avgWaitingTime/num);
	printf("Average turn-around time=%f\n",avgTurnaroundTime/num);
	
}
