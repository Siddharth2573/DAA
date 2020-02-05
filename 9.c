#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int partition(int a[],int low,int high)
{
	int i,j,temp,pivot;
	pivot=a[low];
	i=low+1;
	j=high;
	while(1)
	{
		while(i<high&&a[i]<=pivot)
			i++;
		while(a[j]>pivot)
			j--;
		if(i<j)
			a[j]=a[i]+a[j]-(a[i]=a[j]);
				  //swap a[i] and a[j]
		else
		{			
			a[j]=a[low]+a[j]-(a[low]=a[j]);
					//swap a[low] and a[j]	
			return j;
		}
	}
}

void quick_sort(int a[],int low,int high)
{
	int j;
	if(low<high)
	{
		j=partition(a,low,high);
		quick_sort(a,low,j-1);
		quick_sort(a,j+1,high);
	}
}

void main()
{
	int i, n,a[30],ticks;
        double clk;
        clock_t starttime,endtime;
	printf("Enter the number of students: \n");
	scanf("%d",&n);

        for(i=0;i<n;i++) 
            a[i]=rand()%1000; //3 digit #

	printf("The students roll # are:\n");
	for(i=0;i<n;i++) 
            printf("%d\t",a[i]);

        starttime=clock();
	quick_sort(a,0,n-1);
        endtime=clock();

	ticks=abs(starttime-endtime);
        clk=(double)(ticks)/CLOCKS_PER_SEC;

	printf("\nSorted roll numbers are: \n");
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);

	printf("\nValue of CLOCKS_PER_SEC is %ld\n",CLOCKS_PER_SEC);
        printf("\nTotal elapsed clock tickes=%d, The run time is %f seconds\n",ticks, clk);
}
