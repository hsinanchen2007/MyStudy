### 解题思路
此处撰写解题思路

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

int mirror(struct TreeNode* node1, struct TreeNode* node2) {
    if (!node1 && !node2) {
        return 1;
    }
    if (!node1 || !node2) {
        return 0;
    }
    if (node1->val == node2->val) {
        return mirror(node1->left, node2->right) && mirror(node1->right, node2->left);
    } else {
        return 0;
    }
    return 0;
}

bool isSymmetric(struct TreeNode* root){
    return mirror(root, root);
}
```