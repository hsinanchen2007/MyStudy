记录所有和父节点大小关系不对的节点(data)，对data排序，交换最大最小的节点。

```
int cmp(const void *a, const void *b) {
    return ((*(struct TreeNode **)a)->val - (*(struct TreeNode **)b)->val);
}

void dfs(struct TreeNode *root, struct TreeNode *min, struct TreeNode *max, struct TreeNode **data, int *dataSize) {
    if (!root) return;
    if (root->val < min->val) {
        data[(*dataSize)++] = min;
        data[(*dataSize)++] = root;
    }
    if (root->val > max->val) {
        data[(*dataSize)++] = max;
        data[(*dataSize)++] = root;
    }
    dfs(root->left, min, root, data, dataSize);
    dfs(root->right, root, max, data, dataSize);
}

void recoverTree(struct TreeNode *root) {
    struct TreeNode **data = (struct TreeNode **)malloc(sizeof(struct TreeNode *) * 100);
    int dataSize = 0;
    struct TreeNode min, max;
    min.val = INT_MIN;
    max.val = INT_MAX;
    dfs(root, &min, &max, data, &dataSize);
    // Sort the problematic nodes and switch the min and max one
    qsort(data, dataSize, sizeof(struct TreeNode *), cmp);
    int tmp = data[0]->val;
    data[0]->val = data[dataSize - 1]->val;
    data[dataSize - 1]->val = tmp;
}
```
