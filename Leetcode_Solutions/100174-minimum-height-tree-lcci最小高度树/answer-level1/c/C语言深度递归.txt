### 解题思路
此处撰写解题思路

将该题目分解成左子树和右子树的形式

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
struct TreeNode* mySortedArrayToBST(int* nums, int begin, int end)
{   int mid;
    struct TreeNode *root = NULL;

    if (begin > end) {
        return NULL;
    }

    root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    mid = (begin + end) / 2;
    root->val = nums[mid];
    root->left = mySortedArrayToBST(nums, begin, mid - 1);
    root->right = mySortedArrayToBST(nums, mid + 1, end);

    return root;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
    struct TreeNode *root = NULL;
    int mid = 0;
    if (nums == NULL || numsSize <= 0) {
        return NULL;
    }

    root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    mid = (numsSize - 1) / 2;
    root->val = nums[mid];
    root->left = mySortedArrayToBST(nums, 0, mid - 1);
    root->right = mySortedArrayToBST(nums, mid + 1, numsSize - 1);

    return root;
}

```