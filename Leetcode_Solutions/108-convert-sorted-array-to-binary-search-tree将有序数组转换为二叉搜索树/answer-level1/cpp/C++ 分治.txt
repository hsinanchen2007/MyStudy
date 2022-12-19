解题思路：递归 + 分治
细节优化：使用下标代替数组传递，避免vector的创建析构开销
```cpp
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
public:
    TreeNode* satb(vector<int>& nums, int start, int end) {
        if (start >= end) {
            return NULL;
        } else {
            int m = (start + end) / 2;
            auto *root = new TreeNode(nums[m]);
            root->left = satb(nums, start, m);
            root->right = satb(nums, m + 1, end);
            return root;
        }
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return satb(nums, 0, nums.size());
    }
};
```