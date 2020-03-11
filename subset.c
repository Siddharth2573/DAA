#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void main()
{
    int s[20],x[20],n,sum,i,tot,soln=0;
    long int a;
  
    printf("\nEnter the value of n ");
    scanf("%d",&n);
    printf("\nEnter the values ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&s[i]);
    }
    printf("\nEnter the total sum ");
    scanf("%d",&tot);
    printf("\nSolution to the problem is ");
    for(a=0;a<pow(2,n);a=a+1)
    {
        sum=0;
        for(i=0;i<n;i++)
        {
            if((a&(int)pow(2,i))!=0)
            {
                x[i]=1;
                sum=sum+s[i];
            }
            else
            {
                x[i]=0;
            }
        }
        if(sum==tot)
        {
            soln=soln+1;
            printf("\n");
            for(i=0;i<n;i++)
            {
                if(x[i]==1)
                {
                    printf("%d ",s[i]);
                }
            }
        }
    }
    if(soln==0)
    {
        printf("is not possible!!");
    }
   }
