### 题意分析
根据题意可知，每一个预约有两种状态，接收或者拒绝，且**不可以连续接收两个相邻**的预约。那么由此可以推断，**最多连续拒绝2个预约**（若连续拒绝三个，那么接收中间的预约显然是可以有更长的服务时长的），题目要求总的时间最长，就是求**最大的不相邻的子列和**。
### 解题思路
求子列和的问题一般都可以用动态规划来解决。那么解题的关键就是列出状态方程，使用`dp[i]`保存状态，表示**到下标i为止的最大时长**，不难理解，在本题中dp数组的初始状态是

``` 
dp[0] = nums[0];
dp[1] = Math.max(nums[1],nums[0]);
```
dp数组的更新有以下3种情况：

1. 拒绝当前的预约，那么当前最大预约时长不变，为上一个状态的值`dp[i] = dp[i-1]`
2. 接收当前的预约，且上上个请求也是接收的，当前最大预约时长变为`dp[i] = dp[i-2]+nums[i]`
3. 接收当前的预约，且之前连续拒绝两个预约，当前最大预约时长变为`dp[i] = dp[i-3]+nums[i]`(由题意分析可知不会连续拒绝三个请求)

取三个情况中最大的值作为当前dp[i]的值，即
```
if(i>=3)
    dp[i] = Math.max(dp[i-1],dp[i-2]+nums[i],dp[i-3]+nums[i])
else
    dp[i] = Math.max(dp[i-1],dp[i-2]+nums[i])
```
完整的程序如下：
```
var massage = function(nums) {
    if(nums.length === 0) return 0;
    if(nums.length === 1) return nums[0];
    if(nums.length === 2) return Math.max(nums[0],nums[1]);
    var dp = [nums[0],nums[1]];
    var max = 0;
    for(var i = 2;i<nums.length;i++){
        if(i>=3){
            dp[i] = Math.max(dp[i-1],dp[i-2]+nums[i],dp[i-3]+nums[i]);
        }else
            dp[i] = Math.max(dp[i-1],dp[i-2]+nums[i]);
        if(dp[i]>max) max = dp[i];
    }
    return max;
};
```