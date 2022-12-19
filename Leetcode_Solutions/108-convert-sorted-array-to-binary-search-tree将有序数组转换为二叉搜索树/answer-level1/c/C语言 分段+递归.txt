### 解题思路
分段，递归，分段，递归...
![image.png](https://pic.leetcode-cn.com/c1d799a57adb497e2dce91884e4ba9a487801d92ad74f02c908245b9b49a8c1f-image.png)

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
    int inx;
    struct TreeNode *n = NULL;
    if (numsSize <= 0) {
        return NULL;
    }
    n = (struct TreeNode*)calloc(1, sizeof(struct TreeNode));
    if (n == NULL) {
        return NULL;
    }
    inx = numsSize / 2;
    n->val = nums[inx];
    n->left = sortedArrayToBST(nums, inx);
    n->right = sortedArrayToBST(nums + inx + 1, numsSize - inx - 1);
    return n;
}
```