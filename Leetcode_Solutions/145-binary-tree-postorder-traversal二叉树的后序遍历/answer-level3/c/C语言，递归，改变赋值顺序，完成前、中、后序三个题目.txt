```
int g_cnt = 0;
void dfs(struct TreeNode* root, int* res) {
    if (root == NULL) {
        return;
    }
    if (root->left == NULL && root->right == NULL) {
        res[g_cnt++] = root->val;
        return;
    }
    /* 前序放在这里 res[g_cnt++] = root->val;*/
    dfs(root->left, res);
    /* 中序放在这里 res[g_cnt++] = root->val;*/
    dfs(root->right, res);
    /*后序放在这里 */
    res[g_cnt++] = root->val;
    return;
}
int* postorderTraversal(struct TreeNode* root, int* returnSize){
    *returnSize = 0;
    if (root == NULL) {
        return NULL;
    }
    int *res = (int *)malloc(sizeof(int) * 1000);
    g_cnt = 0; //注意全局变量赋个0
    dfs(root, res);
    *returnSize = g_cnt;
    return res;
}
```
