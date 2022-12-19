### 解题思路

### 代码

```cpp
class Solution {
public:
    int rob(vector<int>& nums) {
        /* 未优化内存版本 */
        // 房间数小于3的情况
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);
        
        // 定义状态转移数组，储存全部状态，但是这个题实际上只需要四个变量来储存状态，这样能优化内存
        // 这里为了方便起见，还是使用数组要存储全部状态
        // dp1 表示不偷第一家的状态，dp2 表示偷第一家的状态，即直接把第一家确认偷或者不偷的情况分两个状态记录
        // 注意到偷了第一家，最后一家就不能偷了
        int dp1[nums.size()-1], dp2[nums.size()-1];
        
        // 这里直接确认第一家不偷，从第二家到最后一家计算dp
        dp1[0] = nums[0];
        dp1[1] = max(nums[0], nums[1]);

        // 这里直接确认第一家偷，从第一家到倒数第二家计算dp
        dp2[0] = nums[1];
        dp2[1] = max(nums[1], nums[2]);

        for (int i=2; i<nums.size() - 1; i++){
            dp1[i] = max(nums[i]+dp1[i-2], dp1[i-1]);
            // dp二直接和dp1做偏移nums[i] 和 nums[i+1]
            dp2[i] = max(nums[i+1]+dp2[i-2], dp2[i-1]);
        }
        return max(dp1[nums.size() - 2], dp2[nums.size() - 2]);
    }
};
```