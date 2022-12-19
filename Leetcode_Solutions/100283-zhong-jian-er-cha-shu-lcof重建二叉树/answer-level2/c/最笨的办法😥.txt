```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

 #include <stdio.h>
 #include <stdlib.h>

 struct TreeNode* build(struct TreeNode*, int*, int*, int);
 int locate(int*, int, int);

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
    struct TreeNode* root = (struct TreeNode*) malloc (sizeof(struct TreeNode));
    return build(root, preorder, inorder, preorderSize);
}

struct TreeNode* build(struct TreeNode* root, int* preorder, int* inorder, int size) {
    if (size <= 0) {
        free(root);
        root = NULL;
    } else {
        root->val = preorder[0];
        int location = locate(inorder, size, preorder[0]);
        struct TreeNode* leftRoot = (struct TreeNode*) malloc (sizeof(struct TreeNode));
        root->left = build(leftRoot, preorder + 1, inorder, location);
        struct TreeNode* rightRoot = (struct TreeNode*) malloc (sizeof(struct TreeNode));
        root->right = build(rightRoot, preorder + 1 + location, inorder + 1 + location, size - location - 1);
    }
    return root;
}

int locate(int* array, int arraySize, int target) {
    for (int i = 0; i < arraySize; i++) {
        if (array[i] == target) {
            return i;
        }
    }
    return -1;
}
```
