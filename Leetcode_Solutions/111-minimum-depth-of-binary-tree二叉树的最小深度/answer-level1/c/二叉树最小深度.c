### 解题思路
此处撰写解题思路

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

int min(int a,int b)
{
    if (a>=b)
    {
        return b;
    }
    return a;
}
int minDepth(struct TreeNode* root){
    if (root)
    {
        if (root->right&&root->left)
        {
            return min(minDepth(root->left),minDepth(root->right))+1;
        }
        else if (root->right&&(!root->left))
        {
            return minDepth(root->right)+1;
        }
        else
        {
            return minDepth(root->left)+1;
        }
    }
    else
    {
        return 0;
    }
}
```