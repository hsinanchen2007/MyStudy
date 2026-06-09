### 解题思路
dp[i]表示[0,i]范围并且必须以i为结束的范围内，能取得的最大值
dp[i] = (dp[i-1] > 0 ? dp[i-1] + nums[i] : nums[i])

### 代码

```cpp
class Solution {
public:
    //状态表达式怎么写？
    //dp[i][j]表示数组中[i,j]范围取得的最大值？
    //dp[i][j] = dp[i][j-1]???
    //dp[i]表示数组[0,i]范围取得的最大值？
    //dp[i] = dp[i-1] + (s[i] > 0 ? s[i] : 0)????
    //dp[i]表示[0,i]范围并且必须以i为结束的范围内，能取得的最大值。
    //dp[i] = (dp[i-1] > 0 ? dp[i-1] + nums[i] : nums[i]);

    //O(n)类型的dp有点不太好找状态表达式，感觉有点生搬硬套。
    //与O(n2)的dp不同，这道题最优解不是dp[nums.size()-1],需要记录每次dp的值。
    int maxSubArray(vector<int>& nums) {
        int dp[nums.size()] = {0};
        int maxSum = nums[0];
        dp[0] = nums[0];
        for(int i = 1; i < nums.size(); i++){
            dp[i] = (dp[i-1] > 0 ? dp[i-1] + nums[i] : nums[i]);
            maxSum = max(maxSum, dp[i]);
            cout << i << " " << dp[i] << endl;
        }
        return maxSum;
    }
};
```