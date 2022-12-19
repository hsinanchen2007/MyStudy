### 解题思路
dp[k]表示k之前的和(包括nums[k])，要求i到j之间的和，则为dp[j]-dp[i]+nums[i]

### 代码

```cpp
class NumArray {
public:
    NumArray(vector<int>& nums): nums(nums) {
        if(nums.size() != 0)
        {
            dp.resize(nums.size());
            dp[0] = nums[0];
        }
        for(int k = 1; k < nums.size(); ++k)
        {
            dp[k] = dp[k-1] + nums[k];
        }
    }
    
    int sumRange(int i, int j) {
        if(dp.size() == 0)return 0;
        if(i > j)return 0;
        return dp[j] - dp[i] + nums[i];
    }
    vector<int> dp;
    vector<int> nums;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
```