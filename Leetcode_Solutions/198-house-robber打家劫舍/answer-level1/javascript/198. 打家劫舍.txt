### 解题思路

这是一道经典的 ``动态规划`` 问题，要解决这道题，首先要了解 ``动态规划`` 的特性：

- **最优子结构**：如果问题的最优解所包含的子问题的解也是最优的，就称该问题具有 **最优子结构**
- **无后效性**：某阶段状态一旦确定，则此后过程演变不再受此前各种状态及决策的影响
- **重叠子问题**：即子问题之间是不独立的，一个子问题在下一阶段决策中可能被多次使用到

明显这道题是满足以上特征的。

解题思路如下：
- 对于 $i = 0$ 时，$dp[0] = nums[0]$
- 对于 $i = 1$ 时，$dp[1] = max(dp[0], nums[1])$
- 对于 $i = 2$ 时，$dp[2] = max(dp[1], nums[2] + dp[0])$
- ...
- 对于 $i = n$ 时，$dp[n] = max(dp[n - 1], nums[n] + dp[n - 2]$

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var rob = function(nums) {
    if (!nums.length) {
        return 0
    }
    if (nums.length === 1) {
        return nums[0]
    }
    let dp = [nums[0], Math.max(nums[0], nums[1])]
    for (let i = 2; i < nums.length; i++) {
        dp[i] = Math.max(dp[i - 1], nums[i] + dp[i - 2])
    }
    return dp[dp.length - 1]
};

```
- 时间复杂度：$O(n)$
- 空间复杂度：$O(n)$

### 优化空间复杂度
```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var rob = function(nums) {
    if (!nums.length) {
        return 0
    }
    if (nums.length === 1) {
        return nums[0]
    }
    if (nums.length === 2) {
        return Math.max(...nums)
    }
    let prev = nums[0]
    let curr = Math.max(nums[0], nums[1])
    let max = 0
    for (let i = 2; i < nums.length; i++) {
        max = Math.max(curr, nums[i] + prev)
        prev = curr
        curr = max
    }
    return max
};
```
- 时间复杂度：$O(n)$
- 空间复杂度：$O(1)$