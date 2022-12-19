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


struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
    if (!preorderSize)
        return NULL;
    
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = preorder[0];
    
    int idx = 0;
    while (idx < preorderSize && inorder[idx] != preorder[0])
        idx++;

    root->left = buildTree(preorder + 1, idx, inorder, idx);
    root->right = buildTree(preorder + 1 + idx, preorderSize - idx - 1, inorder + 1 + idx, inorderSize - 1 - idx);
    return root;
}
```