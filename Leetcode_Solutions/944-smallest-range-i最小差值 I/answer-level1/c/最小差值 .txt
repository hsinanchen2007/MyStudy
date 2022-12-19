### 解题思路
遍历找最大值和最小值，求平均值
若最大值、最小值与平均值的差值都处于[-K,K]区间，表他们可以加或减某数后相等，则差值为0
否则最小值需尽可能大，最大值需尽可能小

### 代码

```c

int smallestRangeI(int* A, int ASize, int K){
    int min,max,aver;
    min=max=A[0];
    for(int i=0;i<ASize;i++){
        if(max<A[i])max=A[i];
        if(min>A[i])min=A[i];
    }
    aver=(min+max)/2;
    if(abs(max-aver)<=K&&abs(min-aver)<=K)
        return 0;
    return max-min-K-K;
}
```