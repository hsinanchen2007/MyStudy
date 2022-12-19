
```
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if(root == NULL){
        return NULL;
    }
    if(q->val > root->val && p->val > root->val){
       return lowestCommonAncestor(root->right , p, q);
    }else if(q->val < root->val && p->val < root->val){
       return lowestCommonAncestor(root->left , p, q);
    }
    return root;
}
```
