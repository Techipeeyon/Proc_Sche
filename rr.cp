#include <stdio.h>
struct process
{
	int id,arrival,wait,burst,tottime;
}p[20];

int main() 
{
   int i,n,j,quantum,x;
   float totalwait=0,totalturnaround=0, avgturn,avgwait;
   printf("Enter number of process:");  
   scanf("%d",&n);
   x = n;
   int rem_bt[n];
   for(i=0;i<n;i++)
   {
	printf("Enter process_id:");
	scanf("%d",&p[i].id);
	printf("Enter process arrival time:");
	scanf("%d",&p[i].arrival);
	printf("Enter process burst time:");
	scanf("%d",&p[i].burst);
    rem_bt[i] = p[i].burst;
   }
   printf("Enter the time quantum/time slice:");
   scanf("%d",&quantum);
   int total=0,counter=0;   
   printf("nProcess IDttBurst Timet Turnaround Timet Waiting Timen");
   i = 0;
   while(x!=0)
   {
        if(rem_bt[i]<=quantum && rem_bt > 0)
        {
            total = total + rem_bt[i];
            rem_bt[i] = 0;
            counter = 1;
        }
        else if(rem_bt[i]>0)
        {
            rem_bt[i] -= quantum;
            total += quantum;
        }
        if(rem_bt[i] == 0 && counter == 1)
        {
            x--;
            p[i].tottime = total - p[i].arrival;
            p[i].wait = total - p[i].arrival - p[i].burst;
            printf("\n%d\t\t%d\t\t %d\t\t\t %d", p[i].id, p[i].burst,p[i].tottime,p[i].wait);
            totalwait += total - p[i].arrival - p[i].burst;
            totalturnaround += total - p[i].arrival;
            counter = 0;
        }
        if(i == n-1)
        {
              i = 0;
        }
        else if(p[i + 1].arrival <= total)
        {
              i++;
        }
        else
        {
              i = 0;
        }
   }
   printf("\nAverage waiting time = %f", (float)totalwait / (float)n);
   printf("\nAverage turnaround time = %f\n", (float)totalturnaround / (float)n);
   
   return 0;
}
