### 解题思路
定义一个数组maxLeng[],maxLength[i]表示:nums[i]作为子序列最后一个数字的时候，这个子序列的长度，初始的时候每个nums[i]都是独立的一个子序列，所以每个maxLength[i]都是1
计算maxLength[i]:从nums[0]到nums[i-1],nums[i]可以接到以 比nums[i]小的数结尾的子序列 的后面，所以maxLength[i]就是 所有maxlength[比num[i]小的下标]+1中最大的那一个。
计算完毕之后返回maxlength中的最大值

### 代码

```c
int lengthOfLIS(int* nums, int numsSize){
    if(numsSize==0)return 0;
    if(numsSize==1)return 1;

    int maxLength[numsSize],max=0;
    for(int i=0;i<numsSize;++i)
    {
        maxLength[i]=1;
        for(int j=0;j<i;++j)
            if(nums[i]>nums[j])
                maxLength[i]=maxLength[i]>(maxLength[j]+1)?maxLength[i]:maxLength[j]+1;
        max=max>maxLength[i]?max:maxLength[i];
    }
    return max;
}
```