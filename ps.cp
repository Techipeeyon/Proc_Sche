#include<stdio.h>
struct process
{
	int id,wait,burst,tottime,priority;
}p[20];
int main()
{
	int i,n,j;
	struct process temp;
	float totalwait=0,totalturnaround=0, avgturn,avgwait;
	printf("Enter number of process:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter process_id:");
		scanf("%d",&p[i].id);
		printf("Enter process burst time:");
		scanf("%d",&p[i].burst);
		printf("Enter process priority:");
		scanf("%d",&p[i].priority);
	}
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(p[i].priority>p[j].priority)
			{
				temp = p[j];
				p[j] = p[i];
				p[i] = temp;
			} 
		}
	}
	p[0].wait=0;
	totalwait = p[0].wait;
	for(i=1;i<n;i++)
	{
		p[i].wait = p[i-1].wait + p[i-1].burst;
		totalwait=totalwait+p[i].wait;
	}
	for(i=0;i<n;i++)
	{
		p[i].tottime=p[i].wait+p[i].burst;
		totalturnaround=totalturnaround+p[i].tottime;
	}
	avgturn=totalturnaround/n;
	avgwait=totalwait/n;
	printf("Process Id\tBurst time\tWaiting time\tTurn around time");
	for(i=0;i<n;i++)
	{
		printf("\n%d\t\t%d\t\t%d\t\t%d\n",p[i].id,p[i].burst,p[i].wait,p[i].tottime);
	}
	printf("Average waiting time %f\n",avgwait);
	printf("Average turnaround time %f\n",avgturn);
	return 0;
}
