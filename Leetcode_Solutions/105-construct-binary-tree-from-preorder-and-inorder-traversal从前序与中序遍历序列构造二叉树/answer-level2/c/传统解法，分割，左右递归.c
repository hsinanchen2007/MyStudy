### 解题思路
分割，左右递归

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

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
    if (preorder == NULL || inorder == NULL)
        return NULL;
    if (preorderSize == 0 || inorderSize == 0)
        return NULL;

    struct TreeNode *root = malloc(sizeof(struct TreeNode));
    root->val = preorder[0];
    
    int len = 0;
    for (len = 0; len < inorderSize; len++) {
        if (preorder[0] == inorder[len]) {
            break;
        }
    }

    root->left = buildTree(preorder + 1, len, inorder, len);
    root->right = buildTree(preorder + 1 + len, preorderSize - len -1, inorder + len + 1, inorderSize - len - 1);

    return root;
}
```