### 解题思路
纯C

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


void flatten(struct TreeNode* root){
    struct TreeNode* tmp = NULL;

    while (root)
    {
        if (root->left)
        {
            tmp = root->left;

            while (tmp->right) // 找左子树的最右节点
            {
                tmp = tmp->right;
            }

            tmp->right = root->right;
            root->right = root->left; 
            root->left = NULL;
        }
        root = root->right;
    }
}

```