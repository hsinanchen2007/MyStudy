### 解题思路
说实话刚开始看了这道题，感觉我是个憨憨，连个简单题都不知道怎么写，O（n2）又不行

后来灵机一动，利用动态规划的思路来解题

一维dp数组来存放最大子序和，dp[0]就是nums[0]
这个时候遍历1~nums.length
要得到最大的子序和，就只有两种方法，如果右边比左边小，那么加上右边，如果右边比左边大，那么舍去左边
得到动态转移方程：dp[i]==Math.max(nums[i],dp[i-1]+nums[i])
最后返回dp中的最大值max

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSubArray = function(nums) {
    var dp=new Array(nums.length);
    var max=-Infinity;
    dp[0]=nums[0]
    for (let i=1;i<nums.length;i++){
        dp[i]=Math.max(nums[i],dp[i-1]+nums[i])
    }
    max=Math.max(...dp)
    return max
};
```