## 解题思路
### 以nums=[1,2,3],target=4为例：
![新建 Microsoft Visio Drawing.png](https://pic.leetcode-cn.com/4584cffed0a22d2af3d6cf1df437e4913667a5d9d9b9a069f6b835d145e643eb-%E6%96%B0%E5%BB%BA%20Microsoft%20Visio%20Drawing.png)
#### 设dp数组，dp[target]=target对应的组合数
#### dp[4] = dp[4-nums[0]]+dp[4-nums[1]]+dp[4-nums[2]]=dp[3]+dp[2]+dp[1];
#### dp[3] = dp[3-nums[0]]+dp[3-nums[1]]+dp[3-nums[2]]=dp[2]+dp[1]+dp[0];
#### dp[2] = dp[2-nums[0]]+dp[2-nums[1]]=dp[1]+dp[0];
#### dp[1]=dp[1-nums[0]]=dp[0];
#### 所以初始状态为dp[0] = 1
#### 状态转移规律为dp[target] = dp[target-nums[0]] + dp[target - nums[1]] + ... + dp[target - nums[nums.length-1]]
 
## 代码
```java
class Solution {
    public int combinationSum4(int[] nums, int target) {
        int[] dp = new int[target + 1];
        dp[0] = 1;
        for(int i = 1; i <= target; i ++){
            //计算dp[i]对应的组合数
            for(int j = 0; j < nums.length; j ++){
                if(i >= nums[j]){
                    dp[i] += dp[i - nums[j]];
                }
            }
        }
        return dp[target];
    }
}
```