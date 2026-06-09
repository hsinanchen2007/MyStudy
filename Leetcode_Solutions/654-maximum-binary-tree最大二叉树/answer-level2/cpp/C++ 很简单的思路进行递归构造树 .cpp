```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    TreeNode* helper(const vector<int>& nums)
    {
        auto it = max_element(nums.begin(), nums.end());
        if (it == nums.end())   return nullptr;
        TreeNode* root = new TreeNode(*it);
        root->left = helper(vector<int>(nums.begin(), it));
        root->right = helper(vector<int>(it + 1, nums.end()));

        return root;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* root = helper(nums);

        return root;    
    }
};
```
递归构造树的左右结点，找最大值应该用二分查找，会有常数项上的优化。
推荐[单调栈](https://leetcode-cn.com/problems/maximum-binary-tree/solution/c-dong-tai-gui-hua-by-infinite-15-7/)的解法，很有意思，第一时间没想到，手动压栈是单调栈的做法，时间/空间复杂度都很不错的解法。