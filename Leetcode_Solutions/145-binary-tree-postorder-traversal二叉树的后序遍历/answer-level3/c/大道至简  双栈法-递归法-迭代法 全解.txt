![image.png](https://pic.leetcode-cn.com/f0403247b66a542fb9b23c2a1b3bfb57a8e05c68f654818b3c610ba8a7fdab16-image.png)

```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//法一：递归
 void PostOrder(struct TreeNode*root,int *returnSize,int *res)//递归遍历，不多赘述
 {
     if(!root) return ;
     PostOrder(root->left,returnSize,res);
     PostOrder(root->right,returnSize,res);
     res[(*returnSize)++]=root->val;
 }
int TreeSize(struct TreeNode* root)//求得动态树的size
{
    if(!root) return 0;
    return TreeSize(root->left)+TreeSize(root->right)+1;
}


int* postorderTraversal(struct TreeNode* root, int* returnSize){

int size=TreeSize(root);
int *res=malloc(sizeof(int)*size);
*returnSize=0;
PostOrder(root,returnSize,res);

return res;
}
```
//迭代，利用莫里斯遍历，核心模板如下：其中需注意的是，本人利用一个pre指针保存前一个结点的情况来判断是否重复计数
```

int TreeSize(struct TreeNode* root)
{
    if(root==NULL) return 0;
    return TreeSize(root->left)+TreeSize(root->right)+1;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize){

   *returnSize=0;
   if(root==NULL) return NULL;

   int size=TreeSize(root);
   int* res=malloc(sizeof(int)*size);
   struct TreeNode** src=malloc(sizeof(struct TreeNode*)*size);
   struct TreeNode* prev=NULL;

   int top=-1;
   while(root!=NULL||top!=-1)
   {
       if(root)
       {
           src[++top]=root;
           root=root->left;
       }
       else
       {
           root=src[top];
           if(root->right==NULL||root->right==prev)
           {
               res[(*returnSize)++]=root->val;
               top--;
               prev=root;
               root=NULL;
           }
           else
           root=root->right;
       }
   }
return res;
}
```
//双栈法，栈1从左至右依次层次遍历，栈2作为记录栈，最后将栈2中结点值逆序输出即可
思路是：
用一个栈实现 根->右->左 的遍历
用另一个栈将遍历顺序反过来，使之变成 左->右->根
```
# define MAXSIZE 1000
int TreeSize(struct TreeNode*root)
{
    if(root==NULL) return 0;
    return TreeSize(root->left)+TreeSize(root->right)+1;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize){

if(root==NULL)
{
    *returnSize=0;
    return NULL;
}
int size=TreeSize(root);
int *res=malloc(sizeof(int)*size);
struct TreeNode *stc1[MAXSIZE]={0};
struct TreeNode *stc2[MAXSIZE]={0};

int p,r,index;
p=r=-1,index=0;
stc1[++p]=root;
while(p!=-1)
{
    root=stc1[p--];
    stc2[++r]=root;
    if(root->left) stc1[++p]=root->left;
    if(root->right) stc1[++p]=root->right;
}
while(r!=-1)
{
   root=stc2[r--];
   res[index++]=root->val;
}

*returnSize=size;
return res;
}


```
