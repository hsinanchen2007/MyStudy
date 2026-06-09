循环数组，按照右大左小规则，从根开始寻找当前数字在树里的位置，在对应位置创建结构体空间
```
void ss(struct TreeNode* L,int* preorder,int i){
    if(preorder[i]>=L->val)
        if(!L->right){
            L->right=(struct TreeNode*)malloc(sizeof(struct TreeNode));
            L->right->val=preorder[i];
            L->right->right=NULL;
            L->right->left=NULL;
            return ;
        }
        else
            ss(L->right,preorder,i);
    else
        if(!L->left){
            L->left=(struct TreeNode*)malloc(sizeof(struct TreeNode));
            L->left->val=preorder[i];
            L->left->right=NULL;
            L->left->left=NULL;
            return ;
        }
        else
            ss(L->left,preorder,i);
    
}
struct TreeNode* bstFromPreorder(int* preorder, int preorderSize){
    struct TreeNode* L;
    L=(struct TreeNode*)malloc(sizeof(struct TreeNode));
    L->val=preorder[0];
    L->right=NULL;
    L->left=NULL;
    for(int i=1;i<preorderSize;i++)
        ss(L,preorder,i);
    return L;
}
```
