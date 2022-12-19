
1、设置一个max变量用来保存当前最大连续1的个数，
2、设置count变量用来保存当前连续1的个数
3、遍历数组，如果为1，count++，如果为0，比较当前count与max的值，较大的保存到max，然后count清零，继续遍历
注意：因为经常没有考虑特殊值而犯错，所以一定要确定特殊值也符合当前的代码
hahah个人纠错：如果到结尾了都是1，那我也要判断的呀，不能只是遇到为0时才判断count跟max

```
int findMaxConsecutiveOnes(int* nums, int numsSize){
    int max = 0;
    int count = 0;
    
    for(int i = 0; i < numsSize; i++)
    {
        if(nums[i] == 1)
        {
            count++;
        }else{
            max = max > count ? max : count;
            count = 0;
        }
    }
    
    max = max > count ? max : count;
    
    return max;
}
```
