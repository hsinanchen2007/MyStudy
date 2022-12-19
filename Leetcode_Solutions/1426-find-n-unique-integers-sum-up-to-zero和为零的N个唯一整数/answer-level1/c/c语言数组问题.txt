### 解题思路
先动态申请一块空间，然后左右分别从1，-1算起，若n为偶数择n/2位置需要置零，n为奇数则不用。

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sumZero(int n, int* returnSize){
    int *sum=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n/2;i++)
    {
        sum[i]=i+1;
        sum[n-i-1]=(i+1)*(-1);
    }
    if(n%2!=0)
    {
        sum[n/2]=0;
    }
    *returnSize=n;
    return sum;
}
```