### 解题思路
将数组从中间分开，每次取中间节点（numsSize/2）作为根节点，然后将数组前后两部分分别作为左右子树的迭代参数。耗时：8ms；内存：17.4M。

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
    
    struct TreeNode *cur;
    cur=(struct TreeNode*)malloc(sizeof(struct TreeNode));
    int rootNUm=numsSize/2;
    cur->val=nums[rootNUm];
    if(numsSize==1){
        cur->left=NULL;
        cur->right=NULL;
        return cur;
    }
    numsSize--;
    int leftNUm=numsSize-numsSize/2;
    cur->left=sortedArrayToBST(nums,leftNUm);
    nums+=(leftNUm+1);
    cur->right=sortedArrayToBST(nums,numsSize/2);

    return cur;
}
```