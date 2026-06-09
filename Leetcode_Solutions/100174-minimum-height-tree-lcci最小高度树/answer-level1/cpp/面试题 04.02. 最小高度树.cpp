二分法重构二叉搜索树
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
public:
    TreeNode* genBST(vector<int>& nums, int left, int right) {
        if(left > right) return nullptr;
        int mid = (left + right)/2;
        TreeNode* res = new TreeNode(nums[mid]);
        res->left = genBST(nums, left, mid-1);
        res->right = genBST(nums, mid+1, right);
        return res;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return genBST(nums, 0, nums.size()-1);
    }
};
```
