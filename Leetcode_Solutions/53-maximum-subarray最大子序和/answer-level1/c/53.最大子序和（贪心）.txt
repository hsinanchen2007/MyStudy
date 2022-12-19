### 解题思路
首先看到题目，想到了遍历，外层start 从0 到n-1,内层end从start到n-1。显然复杂度O(n^2)。
其次，想着优化为想着能不能优化为O(nlgn)。
忽然想到，貌似可以一步到位O(n)，贪心法。sum若不断增大，更新ans；sum若小于0，sum重新从0开始。

### 代码

```c

//贪心算法.O(n)
int maxSubArray(int* nums, int numsSize){

    int sum = 0;
    int ans = nums[0]-1;    //小技巧
    for(int i = 0; i < numsSize; i++)
    {
        sum += nums[i];

        if(sum > ans)   
            ans = sum;
        if(sum < 0)     //小于0，舍弃，重新开始累积
            sum = 0;
    }
    return ans;
}
```