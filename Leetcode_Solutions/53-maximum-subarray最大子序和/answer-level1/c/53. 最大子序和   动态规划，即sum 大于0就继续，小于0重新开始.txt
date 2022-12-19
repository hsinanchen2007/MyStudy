### 解题思路
给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

示例:

输入: [-2,1,-3,4,-1,2,1,-5,4],
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。


  连续子序列只要是正数，就有用要加上来；连续子序列只要是负数，就利害要抛弃掉重新开始
  这个是能保证取到最大序列的
### 代码

```c

int maxSubArray(int* nums, int numsSize){
    int maxsum = 0;
    int thissum = 0;
    int i = 0, maxitem=nums[0];


    /*全负数时，下面公式cover不了，单独处理*/
    for(i=0; i<numsSize; i++){
        maxitem = maxitem > nums[i] ? maxitem : nums[i];
    }

    if(maxitem < 0)
        return maxitem;

    for(i=0; i<numsSize; i++){
        thissum += nums[i];
        /*
        连续子序列只要是正数，就有用要加上来
        连续子序列只要是负数，就利害要抛弃掉
        */
        if(thissum < 0)
            thissum = 0;
        else if(thissum > maxsum)
            maxsum = thissum;
        
    }
    return maxsum;
}


```