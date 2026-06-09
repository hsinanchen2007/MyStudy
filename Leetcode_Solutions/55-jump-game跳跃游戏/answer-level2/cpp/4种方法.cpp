```
class Solution {
public:
    bool canJump(vector<int>& nums) {
        // 思路一：从左到右，找到能调到的最右边范围
        // 思路二：从右到左，是否能够到达0
        int left = nums.size() - 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            // 找左边界
            if (nums[i] + i >= left)  // i位置能到达左边界
                left = i;  // 更新做边界位置
        }

        return left == 0;

        // 思路一
        //int max_right = 0;
        //for (int i = 0; i < nums.size(); i++) {  // i为到达位置
        //    if (max_right < i)
        //        return false;  // 如果i超过max_right，说明到不了i位置。
        //    max_right = max(max_right, nums[i]+i);
        //}
//
        //return true;
    }
};

// 超出时间限制
// class Solution {
// public:
//     bool canJump(vector<int>& nums) {
//         // 思路：动态规划，dp表中存放
//         vector<bool> dp;
//         dp.push_back(true);
//         for (int i = 1; i < nums.size(); i++) {
//             bool tmp = false;
//             for (int j = 0; j < i; j++) {
//                 if (j + nums[j] >= i)
//                     tmp = tmp || dp[j];
//             }
//             dp.push_back(tmp);
//         }
//         return dp.back();
//     }
// };

// 超出时间限制
// class Solution {
// public:
//     bool canJump(vector<int>& nums) {
//         // 倒序，递归，当前值大于等于到最后一个位置的距离才能到，可以使用动态规划。
//         return canJumpHelper(nums, nums.size() - 1);
//     }
// 
//     bool canJumpHelper(vector<int>& nums, int end) {
//         for (int i = end; i > 0; i--) {
//             if (i + nums[i] >= end)
//                 return canJumpHelper(nums, i);
//             else
//                 return false;
//         }
// 
//         return true;
//     }
// };
```
