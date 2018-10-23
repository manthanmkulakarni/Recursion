//    Finding largets number using recursion

#include<stdio.h>
#include<stdlib.h>

int larget(int ar[],int n)
{
	//  Base condition

    if(n==1)
    return ar[n];
	//  General condition
    if(ar[n-1]>ar[n-2])
    {
        ar[n-2]=ar[n-1];
        
    }

    return larget(ar,n-1);
}

int main()
{
    int n,i,max;
    printf("Enter the number of element in the array\n");
    scanf("%d",&n);
    int ar[n];
    for(i=0;i<n;i++)
    {
        printf("Enter the %d element\n",i+1);
        scanf("%d",&ar[i]);
    }
    max=larget(ar,n);
    printf("The larget of all the elements is %d\n",max);
    return 0;
}
