### 解题思路
对应官方第一种解法

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
typedef struct TreeNode Node;
bool _valid(Node *node, long long leftMax, long long rightMin)
{
    if (!node)
        return true;
    if (node->left && (node->left->val >= node->val || node->left->val <= leftMax))
        return false;
    if (node->right && (node->right->val <= node->val || node->right->val >= rightMin))
        return false;
    return _valid(node->left, leftMax, node->val) && _valid(node->right, node->val, rightMin);
}
bool isValidBST(struct TreeNode *root)
{
    return _valid(root, LONG_MIN, LONG_MAX);
}
```
### 解题思路
对应官方第三种解法，递归版

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
typedef struct TreeNode Node;
bool _valid(Node *node, long long *prev)
{
    if (!node)
        return true;
    if (!_valid(node->left, prev) || *prev >= node->val)
        return false;
    *prev = (long long)node->val;
    return _valid(node->right, prev);
}
bool isValidBST(struct TreeNode *root)
{
    long long prev = LONG_MIN;
    return _valid(root, &prev);
}
```