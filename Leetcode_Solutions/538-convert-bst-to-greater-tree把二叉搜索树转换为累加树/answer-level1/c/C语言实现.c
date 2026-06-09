C语言实现
```C []
void accBST(struct TreeNode *root, int *sum){
    if (NULL == root) return;
    accBST(root->right, sum);
    *sum += root->val;
    root->val = *sum;
    accBST(root->left, sum);
}

struct TreeNode* convertBST(struct TreeNode* root){
    int sum = 0;
    accBST(root, &sum);
    return root;
}
```
