### 解题思路
采用二分法查找
依据A[i-1]<A[i]>A[i+1]为条件逐渐删选最佳区间
代码确实有待优化

### 代码

```c
int peakIndexInMountainArray(int* A, int ASize){
    int i=0;
    i=sea(A,0,ASize,0);
    return i;
}
int sea(int*A ,int min, int max, int v){
    int vau=v + (max-min)/2;
    int i=0;
    if(A[vau]<A[vau+1])
    {
        i=sea(A,vau,max,vau);
        return i;
    }
    if(A[vau-1]>A[vau])
    {
        i=sea(A,min,vau,0);
        return i;
    }
    if(A[vau-1]<A[vau]&&A[vau]>A[vau+1])
        return vau;
    return 0;
}
```