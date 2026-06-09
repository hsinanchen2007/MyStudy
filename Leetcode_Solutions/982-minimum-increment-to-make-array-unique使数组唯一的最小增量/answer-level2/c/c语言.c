### 解题思路
统计每个数字都有多少个，然后循环按顺序置一，统计置一的个数即可
![image.png](https://pic.leetcode-cn.com/a4364dba7a4f6cdc251872eb40ce76af995e8b63842dc479d58d80c27aebc3cf-image.png)


### 代码

```c
int minIncrementForUnique(int* A, int ASize){
    int a[80000]={0},count=0;
    for(int i=0;i<ASize;i++){
        a[A[i]]++;
    }    
    for(int i=0;i<80000;i++){
        if(a[i] > 1){
            a[i+1] += a[i]-1;
            count += a[i]-1;
            a[i] =1;
        }
    }
    return count;
}
```