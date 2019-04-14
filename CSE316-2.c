#include <stdio.h>
 
int main()
{
   int a[100] ,position,i,j,n,temp,value,sum;
   int sum1 = 0;
   int sum2;
   
   printf("Enter the number of pending requests: ");
   scanf("%d", &n);
 
   printf("\nEnter  pending requests: \n", n);
 
   for (i = 0; i < n; i++)
   {
      scanf("%d", &a[i]);
   }
 
   printf("\nEnter the current position of the head: ");
   scanf("%d", &value);
 
   for (i = n - 1; i >= 0; i--)
   {
      a[i+1] = a[i];
   }
   a[0] = value;
   //sorting
   for(i  = 0 ; i < n ; i++)
	{
		for(j  = 0 ; j < n ; j++)
		{
			if ( a[j] > a[j+1] )
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
		    }
		}
	}
	//sorting complete
	printf("\n\n");
	for(i  = 0 ; i < n+1 ; i++)
	{
		printf("%d\t",a[i]);
	}
	// print done
	
	for(i = 0 ; i < n+1 ; i++ )
	{
		if(a[i] == value)
		{
			for(j  = i ; j < n ; j++)
			{
				sum1 = sum1  + (a[j] - a[j+1]);
			}	
		}
	}
	
	int last = a[n];
    for(i = 0 ; i < n+1 ; i++ )
	{ 
		if((a[i] != value) && (a[i] <= value))
		{
			for(j  = 0 ; j < i ; j++)
			{
				sum2 = -(last - a[j]);
				sum2 = sum2  + (a[j] - a[j+1]);
			}	
		}
	}
	printf("\n\nTotal distace travelled is: %d",((-sum1)+(-sum2)) ) ;
}
    

