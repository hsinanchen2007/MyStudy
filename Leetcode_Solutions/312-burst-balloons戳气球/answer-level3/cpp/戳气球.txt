### 解题思路
dp[i][j] 代表戳破 i 到 j之间的气球获得最大硬币数量，不包含nums[i], nums[j]的气球；
递归公式：
     dp[i][j] = max(dp[i][j], dp[i][k]+dp[k][j]+nums[i]*nums[k]*nums[j]);
可将nums数组复制一份到nums_copy（数组长度为n+2），将nums数组元素复制到nums_copy[1] 到 nums_copy[n+1]，并nums_copy的首尾元素置为1；
针对nums_copy做动态规划，dp[0][n+1]即为最后结果。

### 代码

```cpp
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        if (n < 1) {
            return 0;
        } else if (n == 1) {
            return nums[0];
        } else if ( n == 2) {
            return max(nums[0]*nums[1]+nums[1], nums[0]*nums[1]+nums[0]);
        }

        vector<int> nums_copy(n+2, 0);
        nums_copy[0] = 1;
        nums_copy[n+1] = 1;
        for(int i = 0; i < n; ++i) {
            nums_copy[i+1] = nums[i];
        }

        vector<vector<int> > dp(n+2, vector<int>(n+2, 0));
        for(int i = 0; i < n+1; ++i) {
            dp[i][i+1] = 0;
        }
        for(int i = 2; i < n+2; ++i) {
            for(int j = 0; j+i < n+2; ++j) {
                for(int k = j+1; k < j+i; ++k) {
                    dp[j][j+i] = max(dp[j][j+i], dp[j][k]+dp[k][j+i]+nums_copy[j]*nums_copy[k]*nums_copy[j+i]);
                }
            }
        }
        return dp[0][n+1];
    }
};
```