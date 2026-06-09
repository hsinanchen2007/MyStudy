C语言递归解法
 ```
 void inorder(struct TreeNode* root,int* returnSize,int *a)/*中序遍历二叉树*/
{
    if(!root) return;
    inorder(root->left,returnSize,a);
    
    a[(*returnSize)++]=root->val;
    inorder(root->right,returnSize,a);

}
int size(struct TreeNode* root)/*求二叉树数据个数*/
{
    if(!root) return 0;
    return size(root->left)+size(root->right)+1;
}
int* inorderTraversal(struct TreeNode* root, int* returnSize){
      int treesize=size(root);
      int *a=(int*)malloc(treesize*sizeof(int));
      memset(a,0,treesize);
      *returnSize=0;
      inorder(root,returnSize,a);
      return a;
}
```

栈解法
```
int* inorderTraversal(struct TreeNode* root, int* returnSize){
   struct TreeNode **a=(struct TreeNode**)malloc(sizeof(struct TreeNode*)*1000);
   int *b=(int*)malloc(sizeof(int)*10000);
   int i=0,top=0;
   struct TreeNode *p=NULL;
   a[0]=root;/*根指针进栈*/
   while(top!=-1){
       while(a[top]!=NULL) a[++top]=a[top]->left;/*向左走到尽头*/
       top--;/*退出空指针*/
       if(top!=-1){
           p=a[top];
           b[i++]=p->val;
           a[top]=p->right;
       }
   }
   *returnSize=i;
   return b;
   
}


```
