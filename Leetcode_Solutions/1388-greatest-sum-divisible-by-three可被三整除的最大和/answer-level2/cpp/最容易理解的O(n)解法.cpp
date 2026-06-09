**动态规划三要素**

* 最优子结构 （本题中将状态存在dp数组中，其中dp[i]用来存储 S % 3 = i 中的S， 其中S表示当前选择的数字累加和）

* 边界 （*这里因为初始时我们的累计和S=0, 因为我们仅仅能得到dp[0]=0, 显然我们是无法获取dp[1]或者dp[2]的，因为S%3 != (1, 2), 所以我们可以利用-1e7初始化dp[1,2]*）

* 状态转移方程

  * 举例: 如何更新dp[1]的值？设当前选择元素值为nums[i], 那么dp[1]和nums[i]的关系？

  * 设nums[i] % 3 = 0, 那么dp[1] = dp[1] + nums[i] = max(dp[1], dp[1] + nums[i])

  * 设nums[i] % 3 = 1, 那么dp[1] = max(dp[1], dp[0] + nums[i])

  * 设nums[i] % 3 = 2, 那么dp[1] = max(dp[1], dp[2] + nums[i])

  * 设mod = nums[i] % 3 = 2, 将上面三式合并 dp_new[1] = max(dp[1], dp[ (3 + 1 - mod) % 3] + nums[i])

    合并可得 dp_new[j] = max(dp[j], dp[ (3 + 1 - mod) % 3] + nums[i]), 其中j = {0, 1, 2}

```
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> dp(3);
        dp[1] = dp[2] = -1e7;
        for(auto& x : nums) {
            vector<int> dpNext(3);
            int mod = x % 3;
            for(auto &j:{0, 1, 2}) {
                dpNext[j] = max(dp[(3 + j - mod) % 3] + x, dp[j]);
            }
            dp = dpNext;
        }
        return dp[0];
    }
};
```

**总结**：根据S%3 = {0, 1, 2}的状态，不断更新S%3 = 0的最大值，从而求解此题