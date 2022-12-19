
```c
struct TreeNode* bstFromPreorder(int* preorder, int preorderSize){
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    
    root->val = preorder[0];
    root->left = NULL;
    root->right = NULL;
    
    if(preorderSize == 1) return root;
    
    struct TreeNode* p;
    
    for(int i=1; i<preorderSize; i++){
        p = root;
        
        while((preorder[i]<p->val && p->left!=NULL) || (preorder[i]>p->val && p->right!=NULL)){
            if(preorder[i]>p->val)
                p=p->right;
            else
                p=p->left;
        }
        
        struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        node->val = preorder[i];
        node->left = NULL;
        node->right = NULL;
        
        if(preorder[i]>p->val){
            p->right = node;
        }
        else{
            p->left = node;
        }
    }
    
    return root;
}
```
