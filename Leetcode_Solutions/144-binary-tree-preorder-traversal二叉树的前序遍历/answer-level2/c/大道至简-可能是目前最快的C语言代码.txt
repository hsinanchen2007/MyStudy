![image.png](https://pic.leetcode-cn.com/0136dee2bb544a818bb5a2272e3501c3b606a308416174c098d58a7a2fb887e6-image.png)

```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

//迭代法
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAXSIZE 1000

int TreeSize(struct TreeNode* root)
{
    if(!root) return 0;
    return TreeSize(root->left)+TreeSize(root->right)+1;
}

int* preorderTraversal(struct TreeNode* root, int* returnSize){

if(!root)
{
    *returnSize=0;
    return NULL;
}
int size=TreeSize(root);
int *res=malloc(sizeof(int)*size);

struct TreeNode* stack[MAXSIZE]={0};
int top=-1,index=0;

while(root||top!=-1)
{
    while(root)
    {
        stack[++top]=root;
        res[index++]=root->val;
        root=root->left;
    }
    if(top!=-1)
    {
        root=stack[top--];
        root=root->right;
    }

}
*returnSize=index;
return res;
}
```
//递归巧妙解法
```
int TreeSize(struct TreeNode* root)
{
    if(!root) return 0;
    return TreeSize(root->left)+TreeSize(root->right)+1;
}

void Preorder(struct TreeNode *root,int *returnSize,int *res)
{
    if(root==NULL) return ;
    res[(*returnSize)++]=root->val;
    Preorder(root->left,returnSize,res);
    Preorder(root->right,returnSize,res);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize){

int size=TreeSize(root);
int *res=malloc(sizeof(int)*size);
*returnSize=0;
Preorder(root,returnSize,res);

return res;
}
```
