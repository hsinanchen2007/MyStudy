```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* Dfs(int *nums, int start, int end) 
{
    if (start > end) {
        return NULL;
    }
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    int loc = (start + end) / 2;
    //printf("start = %d  end = %d cur = %d(val = %d)\n", start, end, loc, nums[loc]);
    root -> val = nums[loc];
    root -> left = Dfs(nums, start, loc - 1);
    root -> right = Dfs(nums, loc + 1, end);
    return root;
}
struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
    if (numsSize == 0) {
        return NULL;
    }
    struct TreeNode *root;
    int start, end;
    start = 0;
    end = numsSize - 1;
    root = Dfs(nums, start, end);
    return root;
}
```
