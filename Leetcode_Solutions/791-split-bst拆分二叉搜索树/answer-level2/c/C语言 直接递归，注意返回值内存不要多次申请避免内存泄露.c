```
int splitSubBST(struct TreeNode* root, int V, struct TreeNode** left, struct TreeNode** right){
    *left = NULL;
    *right = NULL;
    if (root == NULL) {
        return 0;
    }
    if (root->val <= V) {
        splitSubBST(root->right, V, left, right);    
        root->right = *left;
        *left = root;
    } else {
        splitSubBST(root->left, V, left, right);    
        root->left = *right;
        *right = root;
    }
    return 0;
}

struct TreeNode** splitBST(struct TreeNode* root, int V, int* returnSize){
   struct TreeNode** res = (struct TreeNode**)malloc(2 * sizeof(struct TreeNode*));
    *returnSize = 2;
    res[0] = NULL;
    res[1] = NULL;
    if (root == NULL) {
        return res;
    }
    splitSubBST(root, V, &res[0], &res[1]);    
    return res;
}
```
