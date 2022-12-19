```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode *CreateNode(int val)
{
    struct TreeNode *tmp = NULL;
    tmp = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    tmp->val = val;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}

struct TreeNode* constructMaximumBinaryTree(int* nums, int numsSize){
    if (numsSize == 0) {
        return NULL;
    }

    int i;
    struct TreeNode *root = NULL;
    struct TreeNode *tmp = NULL;
    struct TreeNode *step = NULL;

    for (i = 0 ; i < numsSize; i++) {
        tmp = CreateNode(nums[i]);
        if (root == NULL) {
            root = tmp;
            continue;
        }

        step = root;
label1:
        if (step->val > nums[i]) {
            if (step->right == NULL) {
                step->right = tmp;
                continue;
            } else {
                if (step->right->val < nums[i]) {
                    tmp->left = step->right;
                    step->right = tmp;
                    continue;
                } else {
                    step = step->right;
                    goto label1;
                } 
            }
        } else {
            tmp->left = step;
            root = tmp;
            continue;
        }
    }

    return root;
}
```
