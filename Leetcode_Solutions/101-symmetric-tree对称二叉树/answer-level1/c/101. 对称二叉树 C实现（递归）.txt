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

typedef struct TreeNode node;

bool Recurse(node* r1, node* r2)
{
    if (!r1 && !r2) {
        return true;
    }
    if (!r1 || !r2) {
        return false;
    }
    return (r1->val == r2->val && Recurse(r1->left, r2->right) && Recurse(r2->left, r1->right));
}

bool isSymmetric(struct TreeNode* root){
    if (!root) {
        return true;
    }
    return Recurse(root->left, root->right);
}
```