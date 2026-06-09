### 解题思路
此处撰写解题思路

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
这颗树的深度是左子树和右子树的深度大着+1；原子问题空树返回深度为0，
class Solution {
public:
                                  //求一棵树的深度
    int maxDepth(TreeNode* root) 
    {
        if(!root)                 //空树的深度为零
        return 0;

       else
        return max(maxDepth(root->left),maxDepth(root->right))+1;

    }
};
```