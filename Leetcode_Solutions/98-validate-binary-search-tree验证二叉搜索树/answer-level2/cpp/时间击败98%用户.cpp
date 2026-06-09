![image.png](https://pic.leetcode-cn.com/905e634d5d590226cd06d1c9cf9d030d29269e545b14eaab3854b2a82b3b21a9-image.png)

### 解题思路
每个点：左子树最大值 < 节点值 < 右子树最小值
用每个点 左孩子 < 节点值 < 右孩子，保证左子树的最右值为左子树最大值，右子树最左值为右子树最小值

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
    TreeNode * findMax(TreeNode * root)
    {
        while(root->right)
            root = root->right;
        return root;
    }
    TreeNode * findMin(TreeNode * root)
    {
        while(root->left)
            root = root->left;
        return root;
    }
public:
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        if(root->left && (root->left->val >= root->val || findMax(root->left)->val >= root->val)) 
            return false;
        if(root->right && (root->right->val <= root->val || findMin(root->right)->val <= root->val)) 
            return false;
        return isValidBST(root->left) && isValidBST(root->right);
    }
};
```