### 解题思路
最大连续子列和的动态规划，模板题，没什么好说的。
题目给的测试用例数据很大，没什么意思。

### 代码

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        int dp[len], ans = -0x7fffffff;
        for(int i = 0; i < len; i++){
            dp[i] = nums[i];
            if(i > 0 && dp[i - 1] + nums[i] > dp[i]){
                dp[i] = dp[i - 1] + nums[i];
            }
            if(dp[i] > ans)     ans = dp[i];
        }
        return ans;
    }
};
```