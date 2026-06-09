### 解题思路
中序递归，同时计数，到达K次返回

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
int count;

void mid_order(struct TreeNode *node, int target, int *value)
{
    if (node == NULL)
        return;
    /* 递归找到第K小次递归返回结果 */
    mid_order(node->left, target, value);
    if (count++ == target) {
        *value = node->val;
        return;
    }
    if (count > target)
        return;
    mid_order(node->right, target, value);
}

int kthSmallest(struct TreeNode* root, int k)
{
    int target = k;
    int value;
    count = 1;
    mid_order(root, target, &value);
    return value;
}
```