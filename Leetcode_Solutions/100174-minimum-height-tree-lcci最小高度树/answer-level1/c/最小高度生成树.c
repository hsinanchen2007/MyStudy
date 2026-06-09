### 解题思路
递归生成，范围就low、high、mid=（low+high）/2 不要自己计算数组下标。

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

struct TreeNode *newNode(int Val)
{
    struct TreeNode* node=(struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val=Val;
    node->left=0;
    node->right=0;
    return node;
}
struct TreeNode *newTree(int *nums,int low,int high)
{
    if(low>high)return 0;
    int mid=(low+high)/2;
    struct TreeNode* root=newNode(nums[mid]);
    root->left=newTree(nums,low,mid-1);
    root->right=newTree(nums,mid+1,high);
    return root;
}
struct TreeNode* sortedArrayToBST(int* nums, int numsSize)
{
    return newTree(nums,0,numsSize-1);
}

/* 不要自己这样瞎搞
struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
    if(numsSize<=0) return 0;

    struct TreeNode* root=(struct TreeNode*)malloc(sizeof(struct TreeNode));
    numsSize=numsSize%2==0?numsSize:numsSize-1;
    root->val=nums[numsSize/2];
    root->left=sortedArrayToBST(nums,numsSize/2);
    root->right=sortedArrayToBST(nums+numsSize/2+1,numsSize/2);
    return root;
}*/
```