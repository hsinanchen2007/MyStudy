### 解题思路
简单递归

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

struct TreeNode* creartBST(int* nums, int left, int right)
{
    int l = left;
    int r = right;
    int mid = (l + r) / 2;
    if(mid < l || mid > r)
        return NULL;

    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = *(nums + mid);
    root->left = creartBST(nums, l, mid - 1);
    root->right = creartBST(nums, mid + 1, r);

    return root;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize)
{
    if(numsSize == 0)
        return NULL;

    struct TreeNode* root = creartBST(nums, 0, numsSize - 1);

    return root;
}
```