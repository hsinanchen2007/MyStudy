```
int rangeSumBST(struct TreeNode* root, int L, int R){
    if(!root)  return 0;
    return ((root->val >= L && root->val <= R) ? root->val : 0) + rangeSumBST(root->left,L,R) + rangeSumBST(root->right,L,R);
}
```
