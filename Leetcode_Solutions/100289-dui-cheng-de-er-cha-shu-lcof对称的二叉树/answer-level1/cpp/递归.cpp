### 解题思路


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
    bool isSymmetric(TreeNode *leftTree, TreeNode *rightTree)
    {
        if(!leftTree && !rightTree)return true;  //左右子树都空
        if(!leftTree || !rightTree)return false;  //左右子树有一空
        //运行到这说明左右子树都不空
        if(leftTree->val != rightTree->val)  //左子树节点值与右子树的不等，直接返回false，无需递归了
            return false;
        //运行到这说明左右子树的节点值相等，继续递归判断左右子树、右左子树节点值是否相等
        return isSymmetric(leftTree->left, rightTree->right) && isSymmetric(leftTree->right, rightTree->left);  
    }
    bool isSymmetric(TreeNode* root) {
        if(!root)return true;
        return isSymmetric(root->left, root->right);
    }
};
```