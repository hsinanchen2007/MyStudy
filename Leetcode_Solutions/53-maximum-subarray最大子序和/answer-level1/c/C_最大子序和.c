### 解题思路
从左边到右边依次把元素加到sum上
此次加法的结果>max,更新max
此次加法的结果<0,sum=0，从下一个位置从新选择子序列。

理由：原子序列的和是一个正数，加到当前位置的数的时候，和变成了负数。说明当前位的数只有一个“减少Buff”,最大的子序列一定不能包含这个位置的数。所以从这个数之后作为一个新的子序列的起点。
所有子序列的最大值在max里，从新选择子序列的时候清零的是sum，所以并不会影响子序列和的最大的值。
注意：一定要先更新max再更新sum。
### 代码

```c
int maxSubArray(int* nums, int numsSize){
    int max=(int)((((unsigned)1)<<(sizeof(int)*8-1))|1);
    int sum=0;
    for(int i=0;i<numsSize;++i)
    {   
        max=max>sum+nums[i]?max:sum+nums[i];
        sum=sum+nums[i]>0?sum+nums[i]:0;
    }
    return max;
}
```