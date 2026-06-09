### 解题思路
利用动态规划，sums[i]表示以i结尾的连续字段和，则sums[i]要么为sums[i-1]+nums[i]要么为0。取决于sums[i-1]是否大于零。用t表示上一个结果，sum表示最大和

### 代码

```c
int maxSubArray(int* nums, int numsSize){
    int t = nums[0];
    int sum = nums[0];
    int i;
    for(i=1;i<numsSize;i++)
    {
        if(t>0)
        {
            t+=nums[i];
        }
        else
        {
            t = nums[i];
        }
        if(sum<t)
        {
            sum=t;
        }
    }
    return sum;

}
```