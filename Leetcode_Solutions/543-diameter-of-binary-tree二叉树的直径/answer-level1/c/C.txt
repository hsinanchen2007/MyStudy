### 解题思路
把问题分解为： 直径 = max{左子树的直径，右子树的直径，左子树深度 + 右子树深度}

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

int max (int a,int b) {
    return a > b ? a : b;
}
int travelTree(struct TreeNode * root, int * diameter) {
    if (root == NULL) {
        return 0;
    }
    int left = travelTree(root->left, diameter);
    int right = travelTree(root->right, diameter);
    *diameter = max(*diameter, left + right);
    return 1 + max(left, right);
}

int diameterOfBinaryTree(struct TreeNode* root){
    int diameter = 0;
    travelTree(root, &diameter);
    return diameter;
}
```