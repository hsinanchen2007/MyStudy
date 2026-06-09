先将数组从大到小排列，再从头开始三个三个地判断是否满足组成三角形的条件，满足的直接返回三个值的和。
```c
int largestPerimeter(int* A, int ASize){
    int i,j,max=0,max_index;
    for(i=0;i<ASize;i++){
        max=0;
        for(j=i;j<ASize;j++)
            if (A[j]>max){
                max=A[j];
                max_index=j;}
        j=A[i];
        A[i]=max;
        A[max_index]=j;
    }
    for(i=0;i<ASize-2;i++){
        if(A[i]<A[i+1]+A[i+2]) 
            return A[i]+A[i+1]+A[i+2];
    }
    return 0;
}
```