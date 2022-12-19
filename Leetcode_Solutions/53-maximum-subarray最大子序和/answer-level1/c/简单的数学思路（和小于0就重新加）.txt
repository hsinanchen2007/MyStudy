### 解题思路

### 代码

```c
int maxSubArray(int* nums, int numsSize){
    if(numsSize==1)return nums[0];
    int sum=nums[0],x;
    for(int i=0;i<numsSize;i++)
    {
        x=x+nums[i];
        if(sum<x)sum=x;
        if(x<0)x=0;
    }
    return sum;

}
```