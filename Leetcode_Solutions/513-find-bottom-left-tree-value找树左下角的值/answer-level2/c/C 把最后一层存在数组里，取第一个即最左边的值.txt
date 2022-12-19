```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int g_val[100000] = {0};
int g_index = 0;
int getLen(struct TreeNode* root, int level)
{
    if (root == NULL) {
        return level;
    }
    int left = getLen(root->left, level + 1);
    int right = getLen(root->right, level + 1);
    return left > right ? left : right;
}

void dfs(struct TreeNode* root, int len, int level)
{
    level++;
    if (root->right == NULL && root->left == NULL && level == len) {
        g_val[g_index++] = root->val;
        return;
    }

    if (root->left != NULL) {
        dfs(root->left, len, level);
    }
    if (root->right != NULL) {
        dfs(root->right, len, level);
    }
}
int findBottomLeftValue(struct TreeNode* root){
    memset(g_val, 0, 100000);
    g_index = 0;
    int len = getLen(root, 0);
    dfs(root, len, 0);
    int i;
    return g_val[0];
}
```
