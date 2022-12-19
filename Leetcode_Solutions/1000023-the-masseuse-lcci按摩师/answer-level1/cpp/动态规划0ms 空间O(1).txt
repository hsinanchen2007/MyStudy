### 解题思路
dp[i] 表示 nums[0] ->nums[i]可以打劫的最大的金额
不能打劫相邻2个
打劫i ->dp[i] = dp[i-2] + nums[i]
不打劫i ->dp[i] = dp[i-1];

### 代码

```cpp

class Solution {
public:
    //空间o(n)
    int massage(vector<int>& nums) {
        int size = (int)nums.size();
        if(size == 0) return 0;
        if(size == 1) return nums[0];
        vector<int>dp(size,0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < size; i++) {
            dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
        }
        return dp[size - 1];
    }
    //空间o(1)
    int massage(vector<int>& nums) {
        int size = (int)nums.size();
        if(size == 0) return 0;
        if(size == 1) return nums[0];
        int d0 = nums[0];
        int d1 = max(d0, nums[1]);
        for (int i = 2; i < size; i++) {
            int temp = max(d0 + nums[i], d1);
            d0 = d1;
            d1 = temp;
        }
        return d1;
    }
};
```