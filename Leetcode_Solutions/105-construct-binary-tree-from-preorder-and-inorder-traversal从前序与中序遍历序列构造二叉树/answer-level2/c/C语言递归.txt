参照106题的解法，解法类似

```
int GetInorderIndex(int *inorder, int inorderSize, int val)
{
    for (int i = 0; i < inorderSize; i++) {
        if (inorder[i] == val) {
            return i;
        }
    }
    return 0;
}

struct TreeNode *Build(int left, int right, int *inorder, int inorderSize, int *preorder, int *preorderIndex)
{
    if (left > right) {
        return NULL;
    }

    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    if (root == NULL) {
        return NULL;
    }
    root->val = preorder[*preorderIndex];
    (*preorderIndex)++;

    int inorderIndex = GetInorderIndex(inorder, inorderSize, root->val);
    root->left = Build(left, inorderIndex - 1, inorder, inorderSize, preorder, preorderIndex);
    root->right = Build(inorderIndex + 1, right, inorder, inorderSize, preorder, preorderIndex);

    return root;
}

struct TreeNode *buildTree(int *preorder, int preorderSize, int *inorder, int inorderSize)
{
    if (preorderSize < 1) {
        return NULL;
    }

    int preoderIndex = 0;
    struct TreeNode *result = Build(0, inorderSize - 1, inorder, inorderSize, preorder, &preoderIndex);
    return result;
}
```
