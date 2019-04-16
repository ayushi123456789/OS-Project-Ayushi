#include<stdio.h>
#include<unistd.h>
int main()
{
 int bt[20],at[20],pri[20],tat[20],wt[20],flag[20],ct[20];
 int n,i,j,p[20],largest,tim,temp,burst_time=0;
 int time_quantum,rt[20];
 float avg_wt,avg_tat;

printf("Enter Total Process:");
scanf("%d",&n);
printf("Enter Time Quantum:");
scanf("%d",&time_quantum);
printf("\nEnter Arrival Time, Burst Time and Priority\n");
    for(i=0;i<n;i++)
    {
        printf("\n P[%d] \n",i+1);
        printf("Arrival Time:");
        scanf("%d",&at[i]);    //arival time
        printf("Burst Time:");
        scanf("%d",&bt[i]);    //burst time
        printf("Priority:");
        scanf("%d",&pri[i]);   // priority of the process
        p[i]=i+1;             //these array keep the process number
        flag[i]=0;
        rt[i]=bt[i];
        burst_time=burst_time+bt[i];
    }
    
    //Sorting the process in order of their arrival time
    for (i=0;i<19;i++)
      { 
        for (j=i+1;j<20;j++)
	   {
	    if (at[i]<at[j])//deacreasing order of priority
            {
	          temp=at[j];
	          at[j]=at[i];
              at[i]=temp; //Swaping arival time 
              
              temp=bt[j];
	           bt[j]=bt[i];
              bt[i]=temp; //Swaping Burst time
              
              temp=pri[j];
	          pri[j]=pri[i];
              pri[i]=temp; //Swaping priority
              
              temp=p[j];
	          p[j]=p[i];
              p[i]=temp; //Swaping process number
            }
          }
       }

for (tim=at[0];tim<burst_time;)//here time is set to first arrival time 
{
  for(i=0;i<n;i++)
 { 
   largest=0;//assuming that largest priority is in last address
  if(at[i]<= tim && p[i] !=1 && pri[i]>pri[largest]) //checking condition that its arrival tine is less than first or previous process 
                                                           //and also it hasn't been ended and if its priority is gteater than changing value of largest varible
   {
      largest=i;
   }
 }
 if (rt[largest]<=time_quantum && rt[largest]>0)  // rt is copy of bt ie bt will complete in given time
       {
        tim+=rt[largest];
        ct[largest]=tim;// time=0 initally
        rt[largest]=0;
        flag[largest]=1;//shows that this process is complete
        tat[largest]=ct[largest]-at[largest];
        wt[largest]=tat[largest]-bt[largest];  
       }
 else if (rt[largest] > 0)// value of rt > time_quantum
      {
        rt[largest]-=time_quantum;
        tim+=time_quantum;    //time is ct
        ct[largest]=tim;
      }
}
   for(i=0;i<n;i++)
   {
       avg_wt=avg_wt+wt[i];
       avg_tat=avg_tat+tat[i];
   }
  avg_tat=(avg_tat*1.0)/n;
  avg_wt=(avg_wt*1.0)/n;
 printf("Avrage Waiting Time:%f",avg_wt);
 printf("\nAvrage Turnaround Time: %f",avg_tat);
}

