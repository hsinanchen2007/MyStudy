### 解题思路

01背包求解

1. 计算出数组总和
2. 如果总和模2不为0，返回false
3. 01背包，计算取出的物品能否满足体积为sum/2

### 一维动态规划解决01背包（经典代码模板）

cpp

```cpp
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto n : nums) sum+=n;
        if (sum % 2 ) return false;
        int V = sum /2;
        vector<bool> dp(V+1, false);
        dp[0] = true;
        for (int i = 0; i< nums.size(); i++){
            for (int j = V; j >= nums[i]; j--){
                dp[j] = dp[j] || dp[j - nums[i]];
            }
        }
        return dp[V];
    }
};
```

javascript

```javascript
var canPartition = function (nums) {
    let sum = nums.reduce((prev, v) => {
        return prev + v
    }, 0)
    if (sum % 2 == 1) return false
    let V = sum / 2
    let dp = new Array(target + 1).fill(false)
    dp[0] = true;
    for (let i = 1; i < nums.length; i++) {
        for (let j = V; j >= i && j - nums[i] >= 0; j--) {
            dp[j] = dp[j] || dp[j - nums[i]]
        }
    }
    return dp[target]
};
```

## 二维动态规划实现(不推荐，适用于初学者理解)

两个子集和相等，先求出数组总和，若总和%2==1,返回false
然后再进行01背包求解

dp[i][j] 表示 前i个数和为j是否存在，则有状态转换方程

`dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i]]`

```javascript
var canPartition = function (nums) {
    let sum = nums.reduce((pre, v) => {
        return pre + v
    }, 0)

    if (sum % 2 == 1) return false
    let dp = new Array(nums.length)
    for (let i = 0; i < dp.length; i++) {
        dp[i] = new Array(sum / 2 + 1).fill(false)
    }
    dp[0][0] = true
    dp[0][nums[0]] = true
    for (let i = 1; i < nums.length; i++) {
        for (let j = 0; j <= sum / 2; j++) {
            if (j - nums[i] >= 0) {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i]]
            } else {
                dp[i][j] = dp[i - 1][j]
            }
        }
    }
    return dp[nums.length - 1][sum / 2]
};
```

[更多题解...](https://github.com/muyids/leetcode)