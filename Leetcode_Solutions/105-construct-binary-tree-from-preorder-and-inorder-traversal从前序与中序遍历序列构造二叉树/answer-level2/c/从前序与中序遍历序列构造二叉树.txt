```
typedef struct TreeNode* NodePtr;
NodePtr build(int *preorder, int l1, int r1, int *inorder, int l2, int r2)
{
    int i, llen, rlen;
    NodePtr root = (NodePtr)malloc(sizeof(struct TreeNode));
    root->val = preorder[l1];
    /*找到根节点在中序序列的位置*/
    for(i = l2; i < r2 && inorder[i] != root->val; i++);
    llen = i - l2;
    rlen = r2 - i;
    /*构造左子树*/
    if(llen)
        root->left = build(preorder, l1+1, l1+llen, inorder, l2, l2+llen-1);
    else
        root->left = NULL;
    /*构造右子树*/
    if(rlen)
        root->right = build(preorder, r1-rlen+1, r1, inorder, r2-rlen+1, r2);
    else
        root->right = NULL;
    return root;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize)
{
    if(preorderSize == 0 || inorderSize == 0)
        return NULL;
    return build(preorder, 0, preorderSize-1, inorder, 0, inorderSize-1);
}
```