### 解题思路
递归策略，把父节点的值累加到子节点，然后继续递归求解。例如[1,2,3],把它变成[12]和[13]两颗树，直接求和

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

int sumNumbers(struct TreeNode* root){
    if (root == NULL) {
        return 0;
    }
    int res = 0;
    if (root->left == NULL && root->right == NULL)
        return root->val;
    if (root->left) {
        root->left->val = root->val * 10 + root->left->val;
        res += sumNumbers(root->left);
    }
    if (root->right) {
        root->right->val = root->val * 10 + root->right->val;
        res += sumNumbers(root->right);
    }
    return res;
}
```