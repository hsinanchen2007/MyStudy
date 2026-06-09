### 解题思路
递归，分治的思想。为了保证左右子树高度差小于等于1，将数组一分为二，左边为左子树，右边为右子树。时间复杂度为O(N),空间复杂度为O(logN).m为root结点。
### 代码

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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildBST(nums, 0, nums.size() - 1);
    }
private:
        TreeNode* buildBST(const vector<int>& nums, int l, int r){
            if(l > r) return nullptr;
            int m = l + (r - l) / 2;
            TreeNode* root = new TreeNode(nums[m]);
            root->left = buildBST(nums, l, m - 1);
            root->right = buildBST(nums, m + 1, r);
            return root;
        }
};
```