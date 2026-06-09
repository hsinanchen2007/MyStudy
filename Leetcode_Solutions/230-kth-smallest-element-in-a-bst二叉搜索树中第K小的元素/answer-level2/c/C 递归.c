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

void dfs(struct TreeNode* root, int* k, int* val) {
    if (!root)
        return;
    
    dfs(root->left, k, val);
    if (--(*k) == 0) {
        *val = root->val;
        return;
    }
    dfs(root->right, k, val);
}

int kthSmallest(struct TreeNode* root, int k){
    int val;
    dfs(root, &k, &val);
    return val;
}
```