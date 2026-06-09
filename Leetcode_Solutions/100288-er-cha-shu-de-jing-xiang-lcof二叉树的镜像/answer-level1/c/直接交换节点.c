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

//直接交换节点
struct TreeNode* mirrorTree(struct TreeNode* root)
{
    if(root == NULL)
        return NULL;
    struct TreeNode* cur;
    cur = root->right;
    root->right = root->left;
    root->left = cur;
    mirrorTree(root->left);
    mirrorTree(root->right);
    return root;

}


```