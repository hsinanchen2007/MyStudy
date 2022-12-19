### 解题思路
![image.png](https://pic.leetcode-cn.com/63789d450b8215cf8e3df537aed8477fe1dacb96e4f3e05a65a28360356e0469-image.png)

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

struct TreeNode* DFS(int *nums,int start,int end)
{
    if(start >= end)
    {
        return NULL;
    }

    int mid = (start + end)>>1;

    struct TreeNode *root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val   = nums[mid];
    root->left  = DFS(nums,start,mid);
    root->right = DFS(nums,mid+1,end);

    return root;
}  

struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
    if(NULL == nums||numsSize == 0)
    {
        return NULL;
    }

    return DFS(nums,0,numsSize);
}
```