获取左右子树的深度，依次递归比较比较
```

int getDepth(struct TreeNode *root)
{
    int left;
    int right;

    if (root == NULL) {
        return 0;
    }

    left = getDepth(root->left);
    right = getDepth(root->right);

    return left > right ? left + 1 : right + 1;
}

bool balanced;

void helper(struct TreeNode *root)
{
    int leftDepth;
    int rightDepth;

    if (root == NULL) {
        return;
    }

    leftDepth = getDepth(root->left);
    rightDepth = getDepth(root->right);
    if ((abs(leftDepth - rightDepth) > 1) && (balanced == true)) {
        balanced = false;
    }

    helper(root->left);
    helper(root->right);

    return;
}

bool isBalanced(struct TreeNode* root)
{
    balanced = true;

    if (root == NULL) {
        return true;
    }

    helper(root);

    return balanced;
}
```
