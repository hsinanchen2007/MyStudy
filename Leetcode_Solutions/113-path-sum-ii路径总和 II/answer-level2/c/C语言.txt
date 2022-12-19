`#define maxNum 1024
bool dfs(struct TreeNode* root, int sum, int** ret, \
int* returnSize, int** returnColumnSizes, int level) {
    if (root == NULL) return false;
    ret[*returnSize][level] = root->val;
    if (!root->left && !root->right && sum == root->val) {
        (*returnColumnSizes)[*returnSize] = level + 1;
        (*returnSize)++;
        ret[*returnSize] = malloc(sizeof(int) * maxNum);
        memcpy(ret[*returnSize], ret[*returnSize - 1], sizeof(int) * level);
        return true;
    }
    bool temp1 = dfs(root->left, sum - root->val, ret, returnSize, returnColumnSizes, level + 1);
    bool temp2 = dfs(root->right, sum - root->val, ret, returnSize, returnColumnSizes, level + 1);
    if (temp1 || temp2) return true;
    else return false;
}

int** pathSum(struct TreeNode* root, int sum, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    if (root == NULL) return NULL;
    *returnColumnSizes = malloc(sizeof(int) * maxNum);
    memset(*returnColumnSizes, 0, sizeof(int) * maxNum);
    int** ret = (int**)malloc(sizeof(int*) * maxNum);
    ret[*returnSize] = (int*)malloc(sizeof(int) * maxNum);
    dfs(root, sum, ret, returnSize, returnColumnSizes, 0);
    if (returnSize == 0) {
        free(ret[*returnSize]);
        free(ret);
        free(returnColumnSizes);
        return NULL;
    } else return ret;
}`