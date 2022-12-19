```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct TreeNode * P_TreeNode;
int findMaxIndex(int *nums, int start, int end) {
    int flag = start;
    int max = INT_MIN;
    while(start <= end) {
        if (nums[start] > max) {
            flag = start;
            max = nums[start];
        }
        start++;
    }
    return flag;
}
P_TreeNode makeBinary(int *nums, int start, int end) {
    if (start > end) {
        return NULL;
    }
        //return NUMM;
    int flag = findMaxIndex(nums, start, end);
    P_TreeNode node = (P_TreeNode) malloc(sizeof(struct TreeNode));
    memset(node, 0, sizeof(struct TreeNode));
    node ->val = nums[flag];
    node->left = makeBinary(nums, start, flag - 1); 
    node->right = makeBinary(nums, flag + 1, end);
    return node;
}
struct TreeNode* constructMaximumBinaryTree(int* nums, int numsSize){
    return makeBinary(nums, 0, numsSize -1);
}
```
