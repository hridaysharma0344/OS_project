int main(){
	int i;//loop variable
	float arrival,burst,sum=0;
	static int num;//holds number of process
	struct process proc[10];//array of struct to hold multiple propeties of a single process

	printf("Enter the number of process:");
	scanf("%d",&num);
	
	printf("\nNow, enter the data for the %d processes:\n",num);

	//inputting the arrival time and burst time from the user.
	for(i=0;i<num;i++){
		
		proc[i].name=i+1;
		printf("Process p%d\n",proc[i].name);
		
		printf("Burst time:");
		scanf("%f",&burst);
		proc[i].burst_time=burst;
		
		printf("Arrival time:");
		scanf("%f",&arrival);
		proc[i].arrival_time=arrival;
		
		proc[i].status=0;
		sum+=proc[i].burst_time;

		printf("\n");
	} 	
	//output the input pricess details
	display(proc,num);
	
	//sort acc to arrival time
	sort(proc,num);
	
	//schedule
	schedule(proc,num,sum);
	
}
