//bubble sort
#include<stdio.h>
#include<time.h>
 main()
{
  	int i,n,temp,j,a[10],key;
	double clk;
	clock_t starttime,endtime;

	printf("Enter the seat capacity of theatre\n");
	scanf("%d",&n);   

	for(i=0;i<n;i++) 
   		a[i]=rand()%100;
    
      printf("The seat # are \n):
	for(i=0;i<n;i++) 
		printf(“%d\n”, a[i]);
   	
   	starttime=clock();
     
for(i=0;i<n-1;i++)
   	{
    		for(j=0;j<n-i-1;j++)
     		{
        		if(a[j]>a[j+1])   
        		{
            			temp=a[j];
           			 a[j]=a[j+1];
            			a[j+1]=temp;
        		}
      	}
   }

    endtime=clock();

    clk=(double)(endtime-starttime)/CLOCKS_PER_SEC;
  
    printf("\n In ascending order of seat after bubble sort: \n");
    for(i=0;i<n;i++)  
    		printf("\t%d",a[i]);

    printf("%f\n",clk);
   }
