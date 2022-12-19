发现数组中最小值和最大值相差大于两倍的K时，最小差值为最大值和最小值之差减两倍的K；当最小值和最大值相差小于或等于两倍的K时，最小差值为0。
```c
int smallestRangeI(int* A, int ASize, int K){
    int i,max=A[0],min=A[0];
    for(i=0;i<ASize;i++){
        if(A[i]>max) max=A[i];
        if(A[i]<min) min=A[i];
    }
    return max-min>2*K?max-min-2*K:0;
}
```