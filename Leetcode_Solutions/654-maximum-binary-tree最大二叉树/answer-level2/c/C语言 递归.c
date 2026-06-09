### 解题思路
仅作为C语言参考代码

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

int maxPosition(int* nums, int low, int high){
    int maxpos = low;
    for(int i = low; i <= high; i++){
        if(nums[i] > nums[maxpos]) 
            maxpos = i;
    }        
    return maxpos; 
}
struct TreeNode* recurContruct(int* nums, int low, int high){
    //注意递归跳出条件    
    if(low > high) return NULL;

    struct TreeNode *root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    int maxpos = maxPosition(nums, low, high);
    root -> val = nums[maxpos];
    root -> left = recurContruct(nums, low, maxpos - 1);
    root -> right = recurContruct(nums, maxpos + 1, high);
    
    return root;
}
struct TreeNode* constructMaximumBinaryTree(int* nums, int numsSize){
    return recurContruct(nums, 0, numsSize - 1);
}
```