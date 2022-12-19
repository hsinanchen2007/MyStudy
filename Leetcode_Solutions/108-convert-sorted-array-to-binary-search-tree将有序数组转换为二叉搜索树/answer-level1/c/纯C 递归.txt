### 解题思路
纯C 递归

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
struct TreeNode* build(int* nums, int left, int right)
{
    if (left > right)
    {
        return NULL;
    }

    int mid = left + (right - left) / 2;
    struct TreeNode* pRoot = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    pRoot->val = nums[mid];

    pRoot->left = build(nums, left, mid - 1);
    pRoot->right = build(nums, mid + 1, right);

    return pRoot;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
    return build(nums, 0, numsSize - 1);
}
```