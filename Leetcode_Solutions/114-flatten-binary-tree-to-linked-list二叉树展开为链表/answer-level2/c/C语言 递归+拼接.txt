### 解题思路

![image.png](https://pic.leetcode-cn.com/cbab5d2442912622ebdc5ff1986323c55c37b494e2a6bd6b3b9a03f11a7f60bf-image.png)

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
struct TreeNode* mostRight(struct TreeNode *node)
{
    while (node->right != NULL) {
        node = node->right;
    }
    return node;
}
struct TreeNode* proc(struct TreeNode* root)
{
    struct TreeNode *cur = NULL;
    struct TreeNode *left = NULL;
    struct TreeNode *right = NULL;
    if (root->left == NULL && root->right == NULL) {
        return root;
    }
    cur = root;
    if (root->left != NULL) {
        left = proc(root->left);
        cur = mostRight(left);
    }
    root->left = NULL;
    if (root->right != NULL) {
        right = proc(root->right);
    }
    root->right = left;
    cur->right = right;
    return root;
}

void flatten(struct TreeNode* root){
    if (root == NULL) {
        return;
    }
    proc(root);
}
```