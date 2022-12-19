- 方法一
由于数组已经排好序，所以将数组元素平方后不需要再用复杂的算法进行排序。
```c
int* sortedSquares(int* A, int ASize, int* returnSize){
    short i,j=0,k=ASize-1;
    for(i=0;i<ASize;i++) A[i]=A[i]*A[i];
    int* res=malloc(ASize*sizeof(int));
    while(i--)
        if(A[j]>A[k]) res[i]=A[j++];
        else res[i]=A[k--];
    *returnSize=ASize;
    return res;
}
```
- 方法二
该方法较为常规，且有超时风险。
```c
int* sortedSquares(int* A, int ASize, int* returnSize){
    short i=0,j,min,min_index;
    while(i<ASize&&A[i]<0){
        A[i]=-A[i];
        i++;
    }
    for(i=0;i<ASize;i++){
        min=A[i];
        min_index=i;
        for(j=i+1;j<ASize;j++){
            if(A[j]<min){
                min=A[j];
                min_index=j;
            }
        }
        j=A[i];
        A[i]=min;
        A[min_index]=j;
    }
    *returnSize=ASize;
    int* res=(int*)malloc(ASize*sizeof(int));
    for(i=0;i<ASize;i++) res[i]=A[i]*A[i];
    return res;
}
```