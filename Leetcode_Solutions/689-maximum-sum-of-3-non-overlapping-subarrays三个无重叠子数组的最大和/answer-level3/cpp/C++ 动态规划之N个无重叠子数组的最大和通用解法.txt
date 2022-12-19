# 思路
题目是求三个无重叠子数组的最大和
其实可以拓展到N个无重叠子数组的最大和
1，定义如下：
`sums[i]`代表以`nums[i]`结尾的前`k`个数的和
`dp[i][j]`代表截止到`nums[i]`形成的第`j`个无重叠子数组的最大和
`path[i][j]`代表截止到`nums[i]`形成的第`j`个无重叠子数组以哪个下标为结尾，用来回溯路径
2，状态转移方程为
`dp[i][j] = max{dp[i - 1][j], sums[i] + dp[i - k][j - 1]};`
对应的`path[i][j] = path[i - 1][j]`或`i`

代码如下：
```C++ []
class Solution {
public:
    vector<int> maxSumOfNSubarrays(vector<int>& nums, int k, int n) {
        if (k < 1 || n * k > nums.size()) return {};
        int N = nums.size();
        int s = 0;
        for (int i = 0; i < k; ++i) {
            s += nums[i];
        }
        // 计算每个数的前k个数的前缀和
        vector<int> sums(N, 0);
        sums[k - 1] = s;
        for (int i = k; i < N; ++i) {
            s += nums[i] - nums[i - k];
            sums[i] = s;
        }
        // 动态规划
        vector<vector<int> > dp(N, vector<int>(n + 1, 0));
        vector<vector<int> > path(N, vector<int>(n + 1, 0));
        dp[k - 1][1] = sums[k - 1];
        path[k - 1][1] = k - 1;
        for (int i = k; i < N; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = dp[i - 1][j];
                path[i][j] = path[i - 1][j];
                if (sums[i] + dp[i - k][j - 1] > dp[i][j]) {
                    dp[i][j] = sums[i] + dp[i - k][j - 1];
                    path[i][j] = i;
                }
            }
        }
        // 路径回溯
        vector<int> res;
        int ind = path[N - 1][n];
        res.push_back(ind - k + 1);
        for (int i = n - 1; i > 0; --i) {
            ind = path[ind - k][i];
            res.push_back(ind - k + 1);
        }
        reverse(res.begin(), res.end());
        return res;
    }
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        // 本题就是n=3的特殊情况，因此调用以下函数即可
        return maxSumOfNSubarrays(nums, k, 3);
    }
};
```

![image.png](https://pic.leetcode-cn.com/752866361c2d649825de6559bad46a44a9203f890c47e2ee829aac74d3fde96e-image.png)
