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
struct TreeNode* construct(int* nums, int begin, int end);

struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
    if(!nums || numsSize == 0)
        return NULL;
    return construct(nums, 0, numsSize);
}

struct TreeNode* construct(int* nums, int begin, int end){
    if(begin >= end)
        return NULL;
    //printf("(%d, %d)", begin, end);
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    int mid = (begin + end) / 2;
    root->val = nums[mid];
    root->left = construct(nums, begin, mid);
    root->right = construct(nums, mid+1, end);
    return root;
}
```