# 思路
就是递归，保存一个当前最大深度的值。
# 代码
```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void getDeep(struct TreeNode* root, int *max, int count) {
    if (root != NULL) {
        if (count+1 > *max) {
            *max = count+1;
        }
    } else {
        return;
    }
    getDeep(root->left, max, count+1);
    getDeep(root->right, max, count+1);
}

int maxDepth(struct TreeNode* root){
    int max = 0;
    if (root == NULL) {
        return 0;
    }
    getDeep(root, &max, 0);
    return max;
}
```
