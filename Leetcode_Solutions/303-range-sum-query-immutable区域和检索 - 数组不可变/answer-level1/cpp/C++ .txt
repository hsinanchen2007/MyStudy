### 解题思路
题目304的退化版本。
思路：dp[i+1]代表从0到i的和。那么求某个区间[i~j]的和就是dp[j+1]-dp[i].

### 代码

```cpp
class NumArray {
public:
    vector<int> dp;
    NumArray(vector<int>& nums) {
        dp = vector<int>(nums.size() + 1, 0);
        for (int i=0; i<nums.size(); i++) {
            dp[i+1] = dp[i] + nums[i];
        }
    }
    
    int sumRange(int i, int j) {
        return dp[j+1] - dp[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
```