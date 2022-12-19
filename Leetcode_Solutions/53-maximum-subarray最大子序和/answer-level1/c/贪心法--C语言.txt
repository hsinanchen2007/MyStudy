### 解题思路
此处撰写解题思路

### 代码

```c
int maxSubArray(int* nums, int numsSize){
int i;
int maxSum=nums[0];
int Tsum=0;
for(i=0;i<numsSize;i++)
{
    Tsum+=nums[i];
    if(Tsum>maxSum)
    {maxSum=Tsum;}
    if(Tsum<0)
    {Tsum=0;}
}
return maxSum;
}
```