### 解题思路
此处撰写解题思路
1、递归的思想；
2、注意的是，只有左右两边都有值，才能有多条路径，否则，只有单一路径。

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


int minDepth(struct TreeNode* root){
    if(root == NULL)
    {
        return 0;
    }

    if(root->left == NULL && root->right == NULL)
    {
        return 1;
    }

    int depth = 0, left_depth = 1, right_depth = 1;

    if(root->left != NULL && root->right != NULL)
    {
        left_depth += minDepth(root->left);
        right_depth += minDepth(root->right);
        depth =(left_depth < right_depth)? left_depth: right_depth;
    }
    else if(root->left != NULL)
    {
        depth = left_depth + minDepth(root->left);
    }
    else
    {
        depth = right_depth + minDepth(root->right);
    }

    return depth;
}
```