### 解题思路


### 代码

```c
int maxTurbulenceSize(int* A, int ASize){
    if(ASize<=1) return ASize;
    int cnt=1,maxLen=0,cnt_0=0;

    for(int i=1; i<ASize; i++){
        if(A[i]-A[i-1]==0) A[i-1] = 0,cnt_0++;
        else A[i-1] = A[i]-A[i-1]>0 ? 1 : -1;
    }
    // 1、特殊情况：当数组元素都是一样的数组时，return 1
    if(cnt_0==ASize-1) return 1;
    for(int i=1; i<ASize-1; i++){
        //若前后互为倒数，则 cnt++, 否则重置 cnt
        cnt = A[i]*A[i-1]<0? (cnt+1) : 1;
        //更新最大值
        maxLen = cnt > maxLen? cnt : maxLen;
    }


    return maxLen+1;
}
```