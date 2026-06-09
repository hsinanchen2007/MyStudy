### 解题思路
...写完看了评论区...
大家都写得一个样...
这题太水了

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



struct TreeNode* constructMaximumBinaryTree(int* nums, int numsSize){
	// 
	if(!numsSize) return NULL;
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    int maxnum = 0;
    // 找到区间内最大值位置
    for(int i = 0; i < numsSize; ++i)
        if(nums[i] > nums[maxnum]) maxnum = i;
    
    root -> val = nums[maxnum];
    root -> left = constructMaximumBinaryTree(nums, maxnum);
    root -> right = constructMaximumBinaryTree(nums + maxnum + 1, numsSize - maxnum - 1);
    return root;
}
```