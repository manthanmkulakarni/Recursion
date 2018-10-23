//This program is to implement array adt

#include<stdio.h>
#include<stdlib.h>

void search(int *ar,int *n,int key)
{
    int i=0,f=0;
    for(i=0;i<*n;i++)
    {
     if(key==*(ar+i))
     {
         f=1;
         break;
     }
     
    }
    if(f==1)
    printf("%d is present at position %d\n",key,i+1);
    
    else
    printf("%d is not present in array\n",key);
}

void insert(int *ar,int pos,int *n,int num)
{
    int i=0;
    //Memory for array is reallocated as per the requirement
    ar=(int*)realloc(ar,sizeof(int)*(1+*n));
    //Insertion at the end of the array
    if(pos==*n)
    {
        *(ar+pos-1)=num;
    }
    else
    {
        //Shifting the element to the right in order to accomodate the new element at specified position
        for(i=*n-1;i>=pos;i--)
        {
            *(ar+i)=*(ar+i-1);
            
        }
        *(ar+i)=num;
    }
    (*n)=(*n)+1;
    
}

void delet(int *ar,int *n,int pos)
{
    int i;
    //If the index of array is less than the position entered
    if(*n<pos)
    {
        printf("Invalid position\n");
    }
    else
    {
        int d=*(ar+pos-1);
       for(i=pos-1;i<*n-1;i++)
       {
           *(ar+i)=*(ar+i+1);
           
       }
       printf("Deleted element is %d\n",d);
    
    ar=realloc(ar,sizeof(int)*(*n-2));
    (*n)=(*n)-1;
    }
}
void update(int*ar,int*n,int num,int uval)
{
    int i=0,flg=0;
    for(i=0;i<*n;i++)
    {
	if(num==*(ar+i))
	{
	   flg=1;
	   break;
	}
    }
    //If the required element is found in the array
    if(flg)
    {
	*(ar+i)=uval;
    }
    else
    {
	printf("Value not found\n");
    }
}

void disp(int *ar,int *n)
{
    int i=0;
    printf("Elements in the array are");
     for(i=0;i<*n-1;i++)
    {
        printf(" %d",*(ar+i));
    }
    printf("\n");
}

int main()
{
    
    int f=1,i=1,pos,c,key,uval;
    
    int *ar=(int*)malloc(sizeof(int));
    for(i=1;f;)
    {
    int num;
    printf("1 Insert\n2 Delete\n3 Search\n4 Update\n5 Exit\nEnter your choice\n");
    scanf("%d",&c);
    switch(c)
    {
        case 1:
            printf("Enter the position\n");
            scanf("%d",&pos);
            printf("Enter the element to be inserted\n");
            scanf("%d",&num);
            insert(ar,pos,&i,num);
            disp(ar,&i);
            break;
        case 2:
            printf("Enter the position to delete\n");
            scanf("%d",&pos);
            delet(ar,&i,pos);
            disp(ar,&i);
            break;
        case 3:
            printf("Enter the element to be searched\n");
            scanf("%d",&key);
            search(ar,&i,key);
            
            break;
            
            
        case 4:
            printf("Enter the value to be update\n");
            scanf("%d",&num);
            printf("Enter the element to update\n");
            scanf("%d",&uval);
            update(ar,&i,num,uval);
            disp(ar,&i);
            break;
        case 5:
            f=0;
            break;
    }
            
    }
 return 0;   
}

