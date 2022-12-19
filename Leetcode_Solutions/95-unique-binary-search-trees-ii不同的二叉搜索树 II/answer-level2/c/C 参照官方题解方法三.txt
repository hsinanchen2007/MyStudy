```
struct TreeNode* copyTreeNode(struct TreeNode* root, int offset) {
    if (root == NULL) return NULL;
    struct TreeNode* res = malloc(sizeof(struct TreeNode));
    res->val = root->val + offset;
    res->left = copyTreeNode(root->left, offset);
    res->right = copyTreeNode(root->right, offset);
    return res;
}
struct TreeNode** generateTrees(int n, int* returnSize){
    *returnSize = 0;
    if (n <= 0) return NULL;
    struct TreeNode** res = malloc(sizeof(struct TreeNode*) * 10240);
    struct TreeNode* init = malloc(sizeof(struct TreeNode));
    init->val = 1, init->left = NULL, init->right = NULL;
    if (n == 1) {
        res[(*returnSize)++] = init;
        return res;
    }
    struct TreeNode*** storage = malloc(sizeof(struct TreeNode**) * (n + 1));
    storage[0] = malloc(sizeof(struct TreeNode*) * 2);
    storage[1] = malloc(sizeof(struct TreeNode*) * 2);
    int* storageSize = malloc(sizeof(int) * n);
    memset(storageSize, 0, sizeof(int) * n);
    storage[0][storageSize[0]++] = NULL;
    storage[1][storageSize[1]++] = init;
    for (int i = 2; i < n; i++) {
        storage[i] = malloc(sizeof(struct TreeNode*) * 10240);
        for (int j = 1; j <= i; j++) {
            for (int p = 0; p < storageSize[j - 1]; p++) {
                for (int q = 0; q < storageSize[i - j]; q++) {
                    struct TreeNode* mid = malloc(sizeof(struct TreeNode));
                    mid->val = j;
                    mid->left = copyTreeNode(storage[j - 1][p], 0);
                    mid->right = copyTreeNode(storage[i - j][q], j);
                    storage[i][storageSize[i]++] = mid;
                }
            }
        }
    }
    for (int j = 1; j <= n; j++) {
        for (int p = 0; p < storageSize[j - 1]; p++) {
            for (int q = 0; q < storageSize[n - j]; q++) {
                struct TreeNode* mid = malloc(sizeof(struct TreeNode));
                mid->val = j;
                mid->left = storage[j - 1][p];
                mid->right = copyTreeNode(storage[n - j][q], j);
                res[(*returnSize)++] = mid;
            }
        }
    }
    for (int i = 0; i < n || i <= 1; i++) {
        free(storage[i]);
    }
    free(storage);
    free(storageSize);
    return res;
}
```
