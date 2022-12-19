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
bool process(struct TreeNode *root, int val)
{
    if (root == NULL) {
        return true;
    }

    if (root->val != val) {
        return false;
    }

    return process(root->left, val) && process(root->right, val);
}

bool isUnivalTree(struct TreeNode* root){
    if (root == NULL) {
        return true;
    }

    int val = root->val;
    return process(root, val);
}
```