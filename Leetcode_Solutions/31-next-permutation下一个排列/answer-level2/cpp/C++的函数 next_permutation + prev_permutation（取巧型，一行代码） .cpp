class Solution {
public:
    void nextPermutation(vector<int>& nums) 
    {
        next_permutation(nums.begin(), nums.end());
    }
};
//按照 **字典序列** 求出 **当前排列** 的 **下一个排列组合**    **next_permutation**(nums.begin(), nums.end());   如果没有则返回原始状态123456...
//按照 **字典序列** 求出 **当前排列** 的  **上一个排列组合**   **prev_permutation**(nums.begin(), nums.end());   下同