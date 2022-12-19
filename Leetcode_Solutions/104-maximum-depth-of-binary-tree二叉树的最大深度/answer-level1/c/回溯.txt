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

void dfs(struct TreeNode* node, int current, int* ret)
{
    if(node == NULL)
    {
        *ret = current > *ret ? current : *ret;
    }
    else
    {
        current++;

        dfs(node->left, current, ret);
        dfs(node->right, current, ret);
    }
}

int maxDepth(struct TreeNode* root){
    int ret = 0;

    if(root != NULL)
    {
        dfs(root,0,&ret);
    }

    return ret;
}
```