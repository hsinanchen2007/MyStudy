### 解题思路
1、首先找到根节点，实际就是最中间的节点
2、再分别找左子树和右子树，方式是使用递归查找

### 代码

```c
/* *
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * struct TreeNode *left;
 * struct TreeNode *right;
 * };
 */
struct TreeNode *GetTree(int *nums, int numsSize)
{
    if (numsSize <= 0) {
        return NULL;
    }
    struct TreeNode *root = malloc(sizeof(struct TreeNode));
    if (root == NULL) {
        return NULL;
    }
    memset(root, 0x0, sizeof(struct TreeNode));
    int rootPos = (numsSize / 2);
    root->val = nums[rootPos];

    root->left = GetTree(nums, rootPos);
    root->right = GetTree(&nums[rootPos + 1], numsSize - rootPos - 1);
    return root;
}

struct TreeNode *sortedArrayToBST(int *nums, int numsSize)
{
    if (numsSize == 0) {
        return NULL;
    }

    if (numsSize == 1) {
        struct TreeNode *root = malloc(sizeof(struct TreeNode));
        if (root == NULL) {
            return NULL;
        }

        memset(root, 0x0, sizeof(struct TreeNode));
        root->val = nums[0];
        return root;
    }

    return GetTree(nums, numsSize);
}
```