```
 int getDepth(struct TreeNode* root, int level)
 {
     if (root == NULL) {
         return level;
     }
     int l_level = getDepth(root->left, level + 1);
     int r_level = getDepth(root->right, level + 1);
     return l_level > r_level ? l_level : r_level;
 }
 void dfs(struct TreeNode* root, int *res, int level)
 {
     res[level] = res[level] > root->val ? res[level] : root->val;

     if (root->left == NULL && root->right == NULL) {
         return;
     }

     if (root->left != NULL) {
        dfs(root->left, res, level + 1); 
     }
     if (root->right != NULL) {
        dfs(root->right, res, level + 1);
     }
 }
int* largestValues(struct TreeNode* root, int* returnSize){
    *returnSize = 0;
    if (root == NULL) {
        return NULL;
    }

    int len = getDepth(root, 0);
    int *res = (int*)malloc(sizeof(int) * len);
    int i;
    for (i = 0; i < len; i++) {
        res[i] = INT_MIN;
    }

    dfs(root, res, 0);
    *returnSize = len;
    return res;
}
```
