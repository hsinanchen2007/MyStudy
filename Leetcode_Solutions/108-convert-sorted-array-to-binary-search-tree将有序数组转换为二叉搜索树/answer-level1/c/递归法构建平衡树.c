### 解题思路
递归快乐大法

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


struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
    if(numsSize==0)return NULL;
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    int half=numsSize/2;
    root->val=nums[half];
    if(half!=0){
        root->left=sortedArrayToBST(nums,half);
    }else {
        root->left=NULL;
    }
    if(numsSize-half-1!=0){
        root->right=sortedArrayToBST(nums+half+1,numsSize-half-1);
    }
    else {
        root->right=NULL;
    }
    return root;
}

```