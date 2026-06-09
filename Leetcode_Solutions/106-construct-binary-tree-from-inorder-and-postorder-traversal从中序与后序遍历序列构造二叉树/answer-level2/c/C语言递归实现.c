参照官方题解，C语言递归实现```
```
int GetIndex(int *inorder, int inorderSize, int val)
{
    for (int i = 0; i < inorderSize; i++) {
        if (inorder[i] == val) {
            return i;
        }
    }
    return 0;
}

struct TreeNode *Build(int left, int right, int *inorder, int inorderSize, int *postorder, int *postIndex)
{
    if (left > right) {
        return NULL;
    }

    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = postorder[*postIndex];
    (*postIndex)--;

    int inorderIndex = GetIndex(inorder, inorderSize, root->val);

    root->right = Build(inorderIndex + 1, right, inorder, inorderSize, postorder, postIndex);
    root->left = Build(left, inorderIndex - 1, inorder, inorderSize, postorder, postIndex);

    return root;
}

struct TreeNode *buildTree(int *inorder, int inorderSize, int *postorder, int postorderSize)
{
    if (inorderSize < 1) {
        return NULL;
    }

    int postIndex = postorderSize - 1;
    struct TreeNode *result = Build(0, inorderSize - 1, inorder, inorderSize, postorder, &postIndex);
    return result;
}
```

