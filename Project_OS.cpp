#include<stdio.h>
#include<conio.h>
int fun(int time,int x1 ,int max1,int arv[], int cpu[])
{
	int max2=max1;
	for(int i=0; i<x1; i++)
	{
		if(arv[i]<=time && cpu[i]<=cpu[max2] && cpu[i]!=0 )
		{
			max2=i;
		}
	}
	return max2;
}
int main()
{
	
	int cp , ar ,x, wt=0,tt=0;
	int cpu[x];
	int arv[x];
	char *pro[x];
	printf("Enter how many number of process you want to enter.\n");
	scanf("%d",&x);
	for(int i = 0; i<x ; i++)
	{
		printf("Enter your %d process \n",(i+1));
		scanf("%s",&pro[i]);
	}
    for(int i = 0; i<x ; i++)
    {
    	printf("Enter CPU burst time for %d process \n",(i+1));
	    scanf("%d",&cpu[i]);
	}
	for(int i = 0; i<x ; i++)
	{
		printf("Enter Arival time for %d process \n",(i+1));
	    scanf("%d",&arv[i]);
	}
	int cpu1[x];
	for(int i=0; i<x; i++)
	{
		cpu1[i]=cpu[i];
	}
	int min=arv[0];
	int index;
	for(int i=0 ; i<x ; i++)
	{
		if (min>=arv[i])
		{
			min=arv[i];
			index=i;
		}
	}
	int maxm=cpu[0];
	int max;
	for(int i=0 ; i<x ; i++)
	{
		if (maxm<=cpu[i])
		{
			maxm=cpu[i];
			max=i;
		}
	}
	int t=index;
	int t1=arv[t];
	int count=0;
	int wait_time =0;
	int avgwt=0;
	int turn_time =0;
	for(int t1 ; count!=x; t1++)
	{
		int max3=fun(t1,x,max , arv,cpu);
		cpu[max3]--;
		if(cpu[max3]==0)
		{
			count++;
			wait_time=t1-arv[max3]-cpu1[max3]+1;
			avgwt = avgwt + wait_time;
			turn_time= turn_time+t1-arv[max3]+1;
		}
	}
	wt = avgwt/x;
	tt = turn_time/x;
	printf(" Your avg waiting time is %d \n",wt);
	printf(" Your avg tournarround time is %d \n",tt);
	getch();
}
