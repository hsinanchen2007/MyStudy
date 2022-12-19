执行用时 : 68 ms, 在所有 C 提交中击败了69.57%的用户
内存消耗 : 28.2 MB, 在所有 C 提交中击败了100.00%的用户

```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* constructMaximumBinaryTree(int* nums, int numsSize) {
    if ((nums == NULL) || numsSize <= 0) {
        return NULL;
    }

    int i;
    int maxIdx = 0;
    for (i=0; i<numsSize; i++) {
        if (nums[i] > nums[maxIdx]) {
            maxIdx = i;
        }
    }

    struct TreeNode* node = malloc(sizeof(struct TreeNode));
    node->left = node->right = NULL;
    node->val = nums[maxIdx];

    node->left = constructMaximumBinaryTree(nums, maxIdx);
    node->right = constructMaximumBinaryTree(&nums[maxIdx+1], numsSize - maxIdx - 1);

    return node;
}

```
