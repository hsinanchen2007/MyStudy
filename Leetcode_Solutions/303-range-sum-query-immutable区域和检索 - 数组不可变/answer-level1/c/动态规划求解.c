![Screenshot from 2020-03-20 19-21-53.png](https://pic.leetcode-cn.com/d507fee7cf9b6129bb7af1cbc1da818f8b4eda6b8fc9282dbeaac7b787a54eff-Screenshot%20from%202020-03-20%2019-21-53.png)

通过 sums[i]记录第 0 位到第 i 位的和: sums[i] = nums[0] + nums[1] + …… + nums[i];

动态转移方程 ：  
sums[0] = nums[0];  
sums[i] = sums[i] + sums[i-1];
例如：nums=[-2,0,3,-5,2,-1],则 sums=[-2,-2,1,-4,-2,-3];

求 sumRange(i,j)：
- 若 i == 0，返回 sums[j];
- 若 i > 0,返回 sums[j] - sum[i - 1];

```c
typedef struct
{
    int *sums;
} NumArray;

NumArray *numArrayCreate(int *nums, int numsSize)
{
    int i = 0;
    if(numsSize == 0)
        return NULL;
    NumArray *numArray = (NumArray *)malloc(sizeof(NumArray));
    numArray->sums = (int *)malloc(sizeof(int) * numsSize);
    numArray->sums[0] = nums[0];
    for (i = 1; i < numsSize; i++)
        numArray->sums[i] = numArray->sums[i - 1] + nums[i];
    return numArray;
}

int numArraySumRange(NumArray *obj, int i, int j)
{
    if (i == 0)
        return obj->sums[j];
    return obj->sums[j] - obj->sums[i - 1];
}

void numArrayFree(NumArray *obj)
{
    if(obj!=NULL) free(obj->sums);
    free(obj);
}
```
