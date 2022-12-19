### 解题思路
此处撰写解题思路

### 代码

```c
#define MAX(x,y) (x) > (y) ?(x):(y)
int rob(int* nums, int numsSize){
    int i,j,sum=0;
    if(numsSize==0)
    return 0;
    if(numsSize==1)
    return nums[0];
    if(numsSize==2)
    return MAX(nums[0],nums[1]);
    if(numsSize>=3)
    {
        nums[2]=nums[0]+nums[2];
    for(i=3;i<numsSize;i++)
    {
        if(nums[i-2]>nums[i-3])
        {
            nums[i]+=nums[i-2];
        }
        else
        {
            nums[i]+=nums[i-3];
        }
    }
    }
     return MAX(nums[numsSize-2],nums[numsSize-1]);
}
```