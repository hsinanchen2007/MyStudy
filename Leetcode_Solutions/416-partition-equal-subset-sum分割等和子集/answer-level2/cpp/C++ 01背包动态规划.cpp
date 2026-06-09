# 解法一：
二维动态规划：
1，`dp[i][j]`代表前`i`个数能否找到若干个数组成和为`j`
2，状态转移方程：
`dp[i][j] = dp[i - 1][j - nums[i]] || dp[i - 1][j];`

完整代码如下：
```C++ []
class Solution {
public:
    bool helper(const vector<int>& nums, int target) {
        int N = nums.size();
        vector<vector<bool> > dp(N + 1, vector<bool>(target + 1, false));
        dp[0][0] = true;
        for (int i = 1; i <= N; ++i) {
            dp[i] = dp[i - 1];
            for (int j = target; j >= nums[i - 1]; --j) {
                dp[i][j] = dp[i][j] || dp[i - 1][j - nums[i - 1]];
            }
            if (dp[i][target]) return true;
        }
        return false;
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1) return false;
        return helper(nums, sum >> 1);
    }
};
```
![image.png](https://pic.leetcode-cn.com/c162a63b8764009a73446b32890a756d178576dcd3c1ec0b06235b93bc2806ca-image.png)


# 解法二：
状态压缩动态规划
```C++ []
class Solution {
public:
    bool helper(const vector<int>& nums, int target) {
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = target; j >= nums[i]; --j) {
                dp[j] = dp[j] || dp[j - nums[i]];
                if (dp[target]) return true;
            }
        }
        return false;
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1) return false;
        return helper(nums, sum >> 1);
    }
};
```

![image.png](https://pic.leetcode-cn.com/bcf1844d68ba3edbe88875b3c32e1dc2df45038d4340c0fda925d615b843f22f-image.png)
