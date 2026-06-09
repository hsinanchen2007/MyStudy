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
struct TreeNode* build(int *nums,int left,int right){
    if(left>right){
        return NULL;
    }
    struct TreeNode* t = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    int mid = (left+right)/2;
    t->val = nums[mid];
    t->left = build(nums,left,mid-1);
    t->right = build(nums,mid+1,right);
    return t;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
    return build(nums,0,numsSize-1);
}
```