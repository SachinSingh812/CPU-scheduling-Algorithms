#include<stdio.h> 
int main() 
{ 
  int i,j,n,time,process,flag=0,time_slice,p; 
  int wait_time=0,turnaround_time=0,ct,Arr_t[10],Burst_time[10],rt[10]; 
 
  label:
  printf("\t\t\t\t===============================\n\t\t\t\t\tWelcome Mr.Sudesh\n\t\t\t\t===============================\n");
  printf("\n\n\t\t\t\tSelect the process you want to handle.\n\n\t\t\t\t1. Student requests.\n\n\t\t\t\t2. Faculty requests:\n");
  printf("\n\t\t\t\tYou have selected: ");
  scanf("%d",&p);
 
  switch(p)
  {
  	case 1: 
  			printf("\n\t\t\t\tEnter Total Number of student Process:\t "); 
  			scanf("%d",&n);
  			process=n;
			printf("\n\t\t\t==========================================================="); 
  			for(i=0;i<n;i++) 
  			{			 
    			printf("\n\n\t\t\t\tArrival Time of process S[%d]: ",i+1);
				scanf("%d",&Arr_t[i]);  
    			printf("\n\t\t\t\tBurst Time of process S[%d]: ",i+1); 
    			scanf("%d",&Burst_time[i]); 
    			rt[i]=Burst_time[i]; 
  			}		 
  			printf("\n\t\t\t\tEnter Time slice:\t"); 
  			scanf("%d",&time_slice); 
  			printf("\n\nProcess\t|Turnaround Time|  Waiting Time  |Completion Time| Situation\n\n"); 
  			for(time=0,i=0;process!=0;) 	
			{ 
    		if(rt[i]<=time_slice && rt[i]>0) 
    		{ 
      			time+=rt[i]; 
      			rt[i]=0; 
      			flag=1; 
    		} 
    		else if(rt[i]>0) 
    		{		 
      			rt[i]=rt[i] - time_slice; 
      			time=time + time_slice; 
    		} 
    		if(rt[i]==0 && flag==1) 
    		{ 
      			process--; 
      			wait_time+=time-Arr_t[i]-Burst_time[i]; 
      			turnaround_time+=time-Arr_t[i]; 
				ct = turnaround_time+wait_time;
      			printf("P[%d]\t|\t%d\t|\t%d\t|\t%d\t|\t",i+1,time-Arr_t[i],time-Arr_t[i]-Burst_time[i],ct);
      			if(ct >= 1000)
      			{
      				printf( "Request Declined\n");	
				}
				else
				{
					printf("Request Handled\n");
				}
      			flag=0; 
    		} 
    		if(i==n-1) 
      		i=0; 
    		else if(Arr_t[i+1]<=time) 
      		i++; 
    		else 
      		i=0; 
  			} 
  			printf("\nAverage Waiting Time= %f\n",wait_time*1.0/n); 
  			printf("Avg Query time= %f",turnaround_time*1.0/n); 
			break;
	case 2:	
  			printf("\t\t\t\tEnter Total Number of Faculty Process:\t "); 
  			scanf("%d",&n); 
  			process=n; 
  			printf("\n\t\t\t============================================================"); 
  			for(i=0;i<n;i++) 
  			{			 
    			printf("\n\n\t\t\t\tArrival of process F[%d] :",i+1); 
    			scanf("%d",&Arr_t[i]); 
    			printf("\n\t\t\t\tBurst Time of process S[%d]: ",i+1); 
    			scanf("%d",&Burst_time[i]); 
    			rt[i]=Burst_time[i]; 
  			}		 
  			printf("\t\t\t\tEnter Time slice:\t"); 
  			scanf("%d",&time_slice); 
  			printf("\n\nProcess\t|Turnaround Time|Waiting Time|Completion Time|Situation\n\n"); 
  			for(time=0,i=0;process!=0;) 
  			{ 
    		if(rt[i]<=time_slice && rt[i]>0) 
    		{ 
      			time+=rt[i]; 
      			rt[i]=0; 
      			flag=1; 
    		} 
    		else if(rt[i]>0) 
    		{		 
      			rt[i]-=time_slice; 
      			time+=time_slice; 
    		} 
    		if(rt[i]==0 && flag==1) 
    		{ 
      			process--; 
      			wait_time+=time-Arr_t[i]-Burst_time[i]; 
      			turnaround_time+=time-Arr_t[i]; 
      			ct = turnaround_time+wait_time;
      			printf("P[%d]\t|\t%d\t|\t%d\t|\t%d\t|\t",i+1,time-Arr_t[i],time-Arr_t[i]-Burst_time[i],ct); 
			   if(ct >= 1000)
      			{
      			          printf("Request Declined.\n");	
				}
				else
				{
				          printf("Request Handled.\n");
				}
				flag=0; 
    		} 
    		if(i==n-1) 
      		i=0; 
    		else if(Arr_t[i+1]<=time) 
      		i++; 
    		else 
      		i=0; 
  			} 
  			printf("\nAverage Waiting Time= %f\n",wait_time*1.0/n); 
  			printf("Averageg Query time= %f",turnaround_time*1.0/n); 
			break;
         	default: printf("Entered choices other than 1 or 2: ");
		    goto label;
  }
  return 0;
}
