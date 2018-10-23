#include<stdio.h>
#include<stdlib.h>

int search(int ar[],int n,int key)
{
    if(n>1)
    {
        if(ar[n/2]<key)
        return search(&ar[n/2],n-n/2,key);

        else
        return search(ar,n/2,key);
    }
    else
    {
        if(ar[n]==key)
        return 1;
        else
        return 0;
    }
    
}
int main()
{
    int n,i,key;
    printf("Enter the number of elements of the array\n");
    scanf("%d",&n);
    int ar[n];
    for(i=0;i<n;i++)
    {
        printf("Enter the %d element\n",i+1);
        scanf("%d",&ar[i]);
    }
    printf("Enter the key to be searched\n");
    scanf("%d",&key);
    if(search(ar,n,key))
    printf("%d is found\n",key);

    else
    printf("%d is not found\n",key);

    return 0;
}