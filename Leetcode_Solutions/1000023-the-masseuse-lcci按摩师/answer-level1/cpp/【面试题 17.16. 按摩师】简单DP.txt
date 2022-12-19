## 思路
dp[i]表示[0,i]范围内最大值，遍历每个数，在dp[i - 2] +  nums[i] 和 dp[i - 1]两者取最大值即表示当前位置时最大值。

### 代码
时间复杂度：O(n)
空间复杂度：O(n)
```cpp
class Solution {
public:
    int massage(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) return 0;
        if (size == 1) return nums[0];
        vector<int> dp(size);
        dp[0] = nums[0], dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < size; ++i) {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return dp[size - 1];
    }
};
```