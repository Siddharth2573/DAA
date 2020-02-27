#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0

void maxheap_bottomup(int h[],int n)
{
   	int i,heap,v,j,k;
   	for(i=n/2;i>0;i--) //start with last parent of tree
	{
		k=i;
		v=h[k];
		heap=FALSE;
		while(!heap && (2*k)<=n)
		{
			j=2*k;
			if(j<n)
   	  			if(h[j]<h[j+1])//take largest among left and right values
					j=j+1;
      			if(v>=h[j])//compare largest child with parent node 
				heap=TRUE;
			else
			{
				h[k]=h[j];//bring the largest child to parent
				k=j;
			}
		}
		h[k]=v;//keeping parent in correct place
	}
}

void heapsort(int h[],int n)
{    
	int i,temp;
	if(n<=1)
      		return;
        else
        {
		maxheap_bottomup(h,n);
		h[n]=h[1]+h[n]-(h[1]=h[n]);//bring largest elt at root to last in the array by swap h[1] and h[n]
					   //any swapping method can be used above
		heapsort(h,n-1);//do not consider last largest element which is in correct place for ascending order
				//this is to bring it back to heap and het 2nd largest so on..
   	}
}

void main()
{
	int h[20],n,i,tick;
	double clk;
        clock_t starttime,endtime;
	printf("\n Enter the number of resumes\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++) 
            h[i]=rand()%100;

	printf("The candidates ranks are:\n");
	for(i=1;i<=n;i++) 
            printf("%d\t",h[i]);
	
	maxheap_bottomup(h,n);
	printf("\nRanks after contructing maxheap\n");
	for(i=1;i<=n;i++)
	    printf("%d\t",h[i]);
        
          starttime=clock();
	  heapsort(h,n);
          endtime=clock();

	  tick=endtime-starttime;
          clk=(double)(endtime-starttime)/CLOCKS_PER_SEC;
	  printf("\n The ranks in sorted order: \n");
	  for(i=1;i<=n;i++)
	      printf("%d\t",h[i]);

          printf("\nHeapsort took %d clock ticks and the run time is %f seconds\n",tick,clk);

}
