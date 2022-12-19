### 解题思路
本质上在解决对于第[i] 个人，我接待还是不接待。

判断的标准就是总价值哪个更大， 那么对于接待的话就是当前接待的的价值 + dp[i - 2]

如果不接待的话，就是dp[i - 1].

状态转移方程也不难写dp[i] = Math.max(dp[i - 2] + nums[i - 2], dp[i - 1]);

注：这里为了方便计算，令 dp[0]和 dp[1]都等于 0，真正的第一个接待客人是dp[2],所以 dp[i]对应的是 nums[i - 2]）

ps:个人解题笔记

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var massage = function(nums) {
    let dp=[]
    dp[0]=0
    dp[1]=0
    for(let i=2;i<nums.length+2;i++)
    {
        dp[i]=Math.max((dp[i-2]+nums[i-2]),dp[i-1])
    }

    return dp[nums.length+1]
};
```