### 解题思路
仿照题解的中序遍历思想，中序遍历树，判断如果前一个数大于等于当前数，返回失败。

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

bool inorder(struct TreeNode* root, struct TreeNode **before, bool *state) 
{
    if (*state == 0) {
        return;
    }
    if (!root) {
        *state = 1;
        return;
    }
    inorder(root->left, before, state);
    if ((*before) && (*before)->val >= root->val) {
        *state = 0;
        return;
    }
    (*before) = root;
    inorder(root->right, before, state);
    
    return;
}

bool isValidBST(struct TreeNode* root)
{
    bool state = 1;
    struct TreeNode *before = NULL;
    inorder(root, &before, &state);
    return state;
}
```