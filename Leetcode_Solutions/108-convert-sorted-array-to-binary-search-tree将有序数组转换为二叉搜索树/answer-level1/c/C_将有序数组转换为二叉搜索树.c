### 解题思路
数组中(low+high)/2元素就是根，左边的数组组成左子树，右边的数组组成右子树（递归）

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

void arrayToTree(int* Nums,struct TreeNode** Root,int low,int high)
{
    if(low<=high)
    {
        (*Root)=(struct TreeNode*)malloc(sizeof(struct TreeNode));
        (*Root)->val=Nums[(low+high)/2];
        
        arrayToTree(Nums,&((*Root)->left),low,(low+high)/2-1);
        arrayToTree(Nums,&((*Root)->right),(low+high)/2+1,high);
    }
    else
        *Root=0;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
    struct TreeNode* root;
    arrayToTree(nums,&root,0,numsSize-1);
    return root;
}
```