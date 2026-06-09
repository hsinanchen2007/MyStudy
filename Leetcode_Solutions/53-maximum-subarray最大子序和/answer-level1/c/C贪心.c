### 解题思路
将数组大小为0或1的输出
长度大于等于2的，另建数组，第一个位置与原数组相同，从第二位置开始判断此位置原数加上该数组前一位元素后与该原数比谁更大，
将大值赋值该位置，这样就将到此位置的最大子数组和统计出来
最后输出最大的即可。

### 代码

```c
int maxSubArray(int* nums, int numsSize){

    if(numsSize==1) return nums[0];
    if(numsSize==0) return 0;

    int large[numsSize];
    large[0]=nums[0];
    for(int i=1;i<numsSize;i++) //从第二位开始，计算累积到此位的最大值
    {
        if((large[i-1]+nums[i] )>nums[i] ) large[i] = large[i-1]+nums[i];
        else large[i] = nums[i];
    }

    for(int i=1 ; i<numsSize;i++)   //逐位将当前最大值延续。
    {
        if(large[i-1]>large[i]) large[i] = large[i-1];
    }

    return large[numsSize-1];
}
```