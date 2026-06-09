### 解题思路
此处撰写解题思路
要求返回最大的总数和，但是不能为相邻的两个元素，也就是隔一个取一个或者多个，最后保证结果最大

解决方式：动态规划，如果想知道每个子数组中最大只需比较当前的这个元素加上dp[i-2]是否大于dp[i-1]
大于的话就取dp[i] = dp[i-2] + nums[i]
小于的话就取dp[i] = dp[i-1]
### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var massage = function(nums) {
    const len = nums.length;
    if(len == 0) return 0;//长度为0时
    if(len == 1) return nums[0]//长度为1时
    var dp = new Array(len)//定义长度为len的dp数组
    dp[0] = nums[0]
    dp[1] = Math.max(nums[0],nums[1])
    for(let i = 2;i<len;i++){
        if(dp[i-2] + nums[i] > dp[i-1]){
            dp[i] = dp[i-2] + nums[i]
        } else{
            dp[i] = dp[i-1]
        }
    }
    return dp[len -1]
};
```