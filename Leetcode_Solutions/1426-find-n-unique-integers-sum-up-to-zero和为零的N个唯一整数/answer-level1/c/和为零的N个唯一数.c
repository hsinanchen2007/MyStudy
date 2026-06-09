### 解题思路
对于数组元素个数的奇偶有迟疑的，用low high标记进行操作。

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sumZero(int n, int* returnSize){

    int* nums=(int*)malloc(sizeof(int)*n);

    int low=0,high=n-1;
    int m=1;
    while(low<high)
    {
        nums[low++]=-1*m;
        nums[high--]=m;
        m++;
    }
    if(low==high)
        nums[low]=0;
    *returnSize=n;
    return nums;
}
```