### 解题思路

1、计算左右子树高度，高度差不超过1.
2、左右子树都是平衡二叉树
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
    int getDepth(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int left = getDepth(root->left);
        int right = getDepth(root->right);
        return max(left,right) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        int left = getDepth(root ->left);
        int right = getDepth(root ->right);
        return isBalanced(root->left)&&isBalanced(root->right)&&abs(left - right)<=1;
    }
};
```