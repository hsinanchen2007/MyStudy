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


struct TreeNode* helper(int* nums, int l, int r){
    if(l>r)
    {
        return NULL;
    }
    else
    {
        struct TreeNode *root=malloc(sizeof(struct TreeNode));
        int p=(l+r)/2;
        root->val=nums[p];
        root->left=helper(nums,l,p-1);
        root->right=helper(nums,p+1,r);
        return root;
    }
}
struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
    return helper(nums, 0, numsSize-1);
}

```