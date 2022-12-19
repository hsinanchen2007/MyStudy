因题目一定存在封顶，且峰顶不能是两端，所以定义两个整型变量，利用无限循环，一个从头开始查找，另一个从尾开始查找，直到其中一个满足峰顶条件返回该索引。
```
int peakIndexInMountainArray(int* A, int ASize){
    int i=0,j=ASize-1;
    while(1){
        if(A[i+1]<A[i])
            return i;
        if(A[j-1]<A[j])
            return j;
        i++;
        j--;
    }
    return 0;
}
```
