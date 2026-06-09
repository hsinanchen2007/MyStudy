### 解题思路
没啥好说的

空树返回0，非空树就返回左右子树最大深度+1（root也是1层）.

### 代码

```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int Max(int a,int b)
{
    return a>b?a:b;
}

int maxDepth(struct TreeNode* root)
{
    if(root==NULL) return 0;
    else
    {
        return 1+Max(maxDepth(root->left),maxDepth(root->right));
    }
}
```