![image.png](https://pic.leetcode-cn.com/23826fb58aa665f4da54add5a2ac25657efd2cec8c00d5c9f62f5189a050f7b3-image.png)
```
#define MAX(a,b) ((a)>(b))?(a):(b)
#define MIN(a,b) ((a)<(b))?(a):(b)
int dominantIndex(int* nums, int numsSize)
{

    //先判断如果只有一位，返回0    
    if(numsSize==1) return 0;//在这个地方卡了很久！！！结果少了个= 以后都写成 1==numsSize，且：先决判断条件写在最前面！！！下面的定义放最前面的话，会发生数组越界！！！！

    //先在nums[0]、nums[1]中把最大的给max ，最小的给sec，index为最大的那个的下标    
    int max = MAX(nums[0],nums[1]),sec = MIN(nums[0],nums[1]),index = (nums[0]>nums[1])?0:1;//把这一行从3int定义行改成1行int定义，时间就从4ms减成0ms了。。。。？why？

    //前两个以及指定，从第三个元素开始，比max大，就修改max。比max大但比sec小，修改第二大-->sec，比两者都小->>进行下一次循环判断    
    for(int i = 2;i<numsSize;i++)
    {
        if(nums[i]>max)
        {
            sec = max;
            max = nums[i];
            index = i;
        }else
        {
            if(nums[i]>=sec) sec = nums[i];
        }
    }
    return (max-2*sec)>=0?index:-1;//只要用到分母，就要考虑为0的情况！！如果唯一的第一大max-2*sec>=0，说明符合，返回最大值的下标index，否则不满足：返回-1
}
```
借鉴了评论区的一个思路，优化了下都到100%。但有个玄学的地方不懂，想请教一下大家，int定义的时候我分成三行定义，显示4ms，写成一行定义，0ms。。不懂为啥
