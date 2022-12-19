```
#define MY_MAX(a, b) ((a) > (b) ? (a) : (b))

static int MaxTreePathVal(struct TreeNode *tree)
{
    int value;

    if (tree == NULL) {
        return 0;
    }

    value = tree->val;
    if (tree->left == NULL) {
        value += MaxTreePathVal(tree->right);
        return value;
    }
    if (tree->right == NULL) {
        value += MaxTreePathVal(tree->left);
        return value;
    }
    value += MY_MAX(MaxTreePathVal(tree->left), MaxTreePathVal(tree->right));
    return value;
}

static void DFS(struct TreeNode **tree, int limit)
{
    int newLimit;
    int maxPathValue;

    if (*tree == NULL) {
        return;
    }

    maxPathValue = MaxTreePathVal(*tree);
    //printf("node = %d, maxValue = %d, limit = %d\n", (*tree)->val, maxPathValue, limit);
    if (maxPathValue < limit) {
        (*tree) = NULL;
        return;
    }

    newLimit = limit - (*tree)->val;
    DFS(&(*tree)->left, newLimit);
    DFS(&(*tree)->right, newLimit);
}

struct TreeNode* sufficientSubset(struct TreeNode* root, int limit){
    int maxPathValue;

    if (root == NULL) {
        return NULL;
    }

    DFS(&root, limit);
    return root;
}
```
