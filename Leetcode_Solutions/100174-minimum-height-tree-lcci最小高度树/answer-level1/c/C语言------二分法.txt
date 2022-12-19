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

struct TreeNode*MiddleSearch(int*nums,int low,int high){
    if(low>=high)    return NULL;
    int m=(low+high)/2;
    struct TreeNode*root=(struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val=nums[m];
    root->left=MiddleSearch(nums,low,m);
    root->right=MiddleSearch(nums,m+1,high);
    return root;
}
struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
struct TreeNode*root=MiddleSearch(nums,0,numsSize);
return root;
}
```