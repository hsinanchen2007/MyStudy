### 解题思路
先找根，再裁剪左树，最后裁剪右树
![image.png](https://pic.leetcode-cn.com/f87abb6b7c3ee8164c0960f71a202639d5be9b20ba1791461cf1c34f37a4258e-image.png)

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

struct TreeNode* trimRoot(struct TreeNode *node, int L, int R)
{
    if (node == NULL) {
        return NULL;
    }
    if (node->val >= L && node->val <= R) {
        return node;
    }
    if (node->val < L) {
        return trimRoot(node->right, L, R);
    } else {
        return trimRoot(node->left, L, R);
    }
}

struct TreeNode* trimLeft(struct TreeNode *node, int L)
{
    if (node == NULL) {
        return NULL;
    }
    if (node->val < L) {
        return trimLeft(node->right, L);
    }
    node->left = trimLeft(node->left, L);
    return node;
}

struct TreeNode* trimRight(struct TreeNode *node, int R)
{
    if (node == NULL) {
        return NULL;
    }
    if (node->val > R) {
        return trimRight(node->left, R);
    }
    node->right = trimRight(node->right, R);
    return node;
}

struct TreeNode* trimBST(struct TreeNode* root, int L, int R){
    struct TreeNode* newRoot;
    newRoot = trimRoot(root, L, R);
    trimLeft(newRoot, L);
    trimRight(newRoot, R);
    return newRoot;
}
```