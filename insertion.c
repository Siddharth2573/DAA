

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void insertionsort(int a[], int);

int main()
{
	int n, num[50], i, t;
	clock_t start,end;
	double time;

	printf("Enter number of customers\n");
	scanf("%d", &n);

	for(i = 0; i < n; i++)
		a[i]=rand()%100;
	
	printf("Customers' contact numbers are:\n");
  	for(i = 0; i < n; i++)
     		printf("%d\t", num[i]);

	start=clock();
	insertionsort(num,n);
	end=clock();

	printf("\nSorted contact list in ascending order:\n");

  	for(i = 0; i < n; i++)
   	    printf("%d\t", num[i]);
 
	time=(double)(end-start)/CLOCKS_PER_SEC;
  	printf("\nTime taken for execution=%lf\n",time);
  	return 0;
}

void insertionsort(int num[], int n)
{
	int i,t,j,flag=0;
  	for(i=0;i<n;i++)
 	{
    		t=a[i];
   		for(j=i-1;j>=0;j--)
   		{
     			 if(num[j]>t) 
     			 {
      	 	 		num[j+1]=num[j];
      		 		flag=1;
      	 	 }
        		 else
             	         break;
   		}
    		if(flag)
     		num[j+1]=t;
  	}
}
