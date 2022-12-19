```
int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    if (root == NULL) return NULL;
    int **res = (int **)malloc(sizeof(int *) * 100);
    *returnColumnSizes = (int *)malloc(sizeof(int) * 100);
    struct TreeNode *queue[10000];
    size_t count, begin = 0, end = 1;
    queue[begin] = root;
    while ((count = end - begin)) {
        res[*returnSize] = (int *)malloc(sizeof(int) * count);
        for (int i = 0; i < count; ++i) {
            struct TreeNode *t = queue[begin++];
            if ((*returnSize) % 2 == 0)  // root to level 1, reverse add
                res[*returnSize][i] = t->val;
            else
                res[*returnSize][count - i - 1] = t->val;
            if (t->left)  queue[end++] = t->left;
            if (t->right) queue[end++] = t->right;
        }
        (*returnColumnSizes)[*returnSize] = count;
        (*returnSize)++;
    }
    return res;
}
```
