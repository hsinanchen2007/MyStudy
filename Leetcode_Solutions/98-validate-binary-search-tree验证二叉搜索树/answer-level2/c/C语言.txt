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
#define MIN -2147483649
#define MAX 2147483648

typedef long long ll;

bool isValid(struct TreeNode *root, ll l, ll r)
{
    if (!root)
        return true;
    int val = root->val;
    if (val <= l || val >= r)
        return false;
    return isValid(root->left, l, val) && isValid(root->right, val, r);
}

bool isValidBST(struct TreeNode* root)
{
    return isValid(root, MIN, MAX);
}
```