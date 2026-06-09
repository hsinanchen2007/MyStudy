### 解题思路
遍历求解当前节点的左右子树的深度差值，从而判断是否是平衡二叉树
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
    bool isBalanced(TreeNode* root) {
        if(root==NULL)return true;
        int d=abs(maxDepth(root->left)-maxDepth(root->right));
        if(d>1)return false;
        return isBalanced(root->left)&&isBalanced(root->right);
    }
    //计算二叉树的深度
    int maxDepth(TreeNode* root) {    
        if(root==NULL)return 0;
        return max(maxDepth(root->left),maxDepth(root->right))+1;
    }
};
```