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
int FindRootIndex(int *inorder, int inorderSize, int data)
{
    int index = 0;
    for (int i = 0; i < inorderSize; i++) {
        if (inorder[i] == data) {
            index = i;
            break;
        }
    }
    return index;
}
struct TreeNode* TraveTree(int start, int end, int *inorder, int *preorder, int preStart, int inorderSize)
{
    int rootIndex;
    if (start == end) {
        struct TreeNode* node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        node->val = inorder[start];
        node->left = NULL;
        node->right = NULL;
        return node;
    }
    struct TreeNode* root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = preorder[preStart];
    rootIndex = FindRootIndex(inorder, inorderSize, root->val);
    if (rootIndex - 1 - start >= 0 ) {
        root->left = TraveTree(start, rootIndex - 1, inorder, preorder, preStart + 1, inorderSize);
    } else {
        root->left = NULL;
    }
    if (rootIndex + 1 <= end ) {
        root->right = TraveTree(rootIndex + 1, end, inorder, preorder, rootIndex - start + preStart + 1,  inorderSize);
    } else {
        root->right = NULL;
    }
    return root;
}
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize)
{
    if (!preorderSize || !inorderSize) {
        printf("come");
        return NULL;
    }
    int rootIndex;
    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = preorder[0];
    rootIndex = FindRootIndex(inorder, inorderSize, root->val);
    if (rootIndex - 1 >= 0) {
        root->left = TraveTree(0, rootIndex - 1, inorder, preorder, 1,  preorderSize);
    } else {
        root->left = NULL;
    }
    if (rootIndex + 1 <= inorderSize - 1) {
        root->right = TraveTree(rootIndex + 1, inorderSize - 1, inorder, preorder, rootIndex + 1, preorderSize);
    } else {
        root->right = NULL;
    }
    return root;
}
```