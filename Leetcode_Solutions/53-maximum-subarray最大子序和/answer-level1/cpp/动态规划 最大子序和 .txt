### 动态规划
- 状态表示：`dp` 数组的含义是**以当前数字结尾的最大自序和**

- 如果我们已经得到了 `dp[i-1]` 的值，要计算 `dp[i]` 的值，用类似01背包的思想，只要考虑加不加入前一个数所在的序列, 对应01背包的选择与不选择，要保证最大，只需取两者中较大值即可。
- 状态转移方程： `dp[i] = max(dp[i-1]+nums[i], nums[i])`
- 而返回值 `ans = max{dp[i]}`
### 优化
观察状态转移方程，计算 `dp[i]`时只需 `dp[i-1]`和 `nums[i]`，因此可以直接将计算后的`dp`值保存在`nums`中。
空间复杂度由O(N)降为O(1)
### 代码

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // nums[i] = max(nums[i-1]+nums[i], nums[i]);
        int ans = nums[0];
        for(int i=1;i<nums.size();i++){
            nums[i]=max(nums[i-1]+nums[i],nums[i]); 
            ans = max(ans, nums[i]);
        }
        return ans;
    }
};
```