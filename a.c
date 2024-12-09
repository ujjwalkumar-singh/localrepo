#include<stdio.h>
void traverse(int arr[],int ub){
  int i=0;
  while(i<=ub){
    printf(" %d ",arr[i]);
    i++;
  }
  return;
}
void insert(int arr[],int item,int pos,int ub){
    for(int i=ub+1;i>=pos-1;i--){
        arr[i]=arr[i-1];
    }
    arr[pos-1]=item;
    return ;
}
void delete(int arr[],int pos,int ub){
    for(int i=pos-1;i<=ub-1;i++){
        arr[i]=arr[i+1];
    }
    return;
}
void sort(int arr[],int ub){
    for(int i=1;i<=ub;i++){
        for(int j=0;j<=ub-i;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
               arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    printf("your element has been sorted");
    return;
}
void binarysearch(int arr[],int lb,int ub,int item){
    int beg=lb,end=ub,mid=(beg+end)/2;
    while(arr[mid]!=item && beg<=end){
        mid=(beg+end)/2;
        if(arr[mid]>item) end=mid-1;
        else beg=mid+1;
    }
    if(arr[mid]==item) printf("item is present at %d possition",mid+1);
    else printf("item not found");
    return;
}
void linearsearch(int arr[],int ub,int item){
    int i=0;
    while(arr[i]!=item&&i<=ub){
        i++;
    }
    if(arr[i]==item) printf("element is present at %d",i+1);
    else printf("item not found");
    return;
}
int main(){
    int arr[50],size,i=0;
    int choice,item,pos,dpos,item6;
    printf("enter the size of array= ");
    scanf("%d",&size);
    if(size>50) printf("invalid size");
    else {
        while(i<=size-1){
            printf("enter the element= ");
            scanf("%d",&arr[i]);
            i++;
        }
    do{
    printf("\n\n------operations on array are given below------\n");
    printf("1.traverse\n");
    printf("2.insert\n");
    printf("3.delete\n");
    printf("4.sorting\n");
    printf("5.binary search\n");
    printf("6.linear search\n");
    printf("7.exit\n");
    printf("enter your choice= ");
    scanf("%d",&choice);
    switch(choice){
        case 1:traverse(arr,size-1);
            break;
        case 2:printf("enter the element of insertion");
             scanf("%d",&item);
             printf("enter the position of insertion");
             scanf("%d",&pos);
             insert(arr,item,pos,size-1);
             size=size+1;
             break;
        case 3:printf("enter the position of element of deletion= ");
              scanf("%d",&dpos);
              delete(arr,dpos,size-1);
              size--;
              break;
        case 4:sort(arr,size-1);
             break;
        case 5:printf("enter the element you want to search= ");
             scanf("%d",&item6);
             binarysearch(arr,0,size-1,item6);
             break;
        case 6:printf("enter the element you want to search= ");
            scanf("%d",&item6);
            linearsearch(arr,size-1,item6);
            break;
        
    }
    }while(choice!=8);
    }
    return 0;
}