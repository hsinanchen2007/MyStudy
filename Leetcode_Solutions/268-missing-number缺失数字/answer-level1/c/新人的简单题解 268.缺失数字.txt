### 解题思路
先求和，再逐个减去数组数字，剩下的就是没出现的数字

### 代码

```c
int missingNumber(int* nums, int numsSize)
{
    //printf("%d",numsSize);
    int k=numsSize*((numsSize+1)/2.0);
    for(int i=0;i<numsSize;i++)
    {
        k-=nums[i];
    }
    return k;
}
```