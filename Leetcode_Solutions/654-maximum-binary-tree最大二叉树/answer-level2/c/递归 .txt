### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/8dd76e6ca29c0a9bc99d45864df17dbb04c617deee6b9cb751bbba1a9b0ff421-image.png)

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
int get_max(int *nums, int start, int end)
{
    int res = start;
    for (int i = start; i < end; i++) {
        if (nums[i] > nums[res]) {
            res = i;
        }
    }

    return res;
}

struct TreeNode* process(int* nums, int start, int end){
    //printf("start = %d, end = %d\n", start, end);
    if (start >= end) {
        return NULL;
    }

    int max = get_max(nums, start, end);
    struct TreeNode *root = calloc(1, sizeof(struct TreeNode));
    root->val = nums[max];
    root->left = process(nums, start, max);
    root->right = process(nums, max + 1, end);
    
    return root;
}

struct TreeNode* constructMaximumBinaryTree(int* nums, int numsSize){
    return process(nums, 0, numsSize);
}
```