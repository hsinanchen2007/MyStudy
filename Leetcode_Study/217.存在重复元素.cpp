/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 */

/*

https://leetcode.cn/problems/contains-duplicate/

217. 存在重复元素

简单
897
company
亚马逊
company
微软 Microsoft
company
彭博 Bloomberg
给你一个整数数组 nums 。如果任一值在数组中出现 至少两次 ，返回 true ；如果数组中每个元素互不相同，返回 false 。
 

示例 1：

输入：nums = [1,2,3,1]
输出：true

示例 2：

输入：nums = [1,2,3,4]
输出：false

示例 3：

输入：nums = [1,1,1,3,3,4,3,2,4,2]
输出：true
 

提示：

1 <= nums.length <= 105
-109 <= nums[i] <= 109

*/

// @lc code=start
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        
        for (int i = 0; i < nums.size(); i++) {
            if (s.find(nums[i]) != s.end()) {
                return true;
            }
            s.insert(nums[i]);
        }
        
        return false;
    }
};


// @lc code=end

