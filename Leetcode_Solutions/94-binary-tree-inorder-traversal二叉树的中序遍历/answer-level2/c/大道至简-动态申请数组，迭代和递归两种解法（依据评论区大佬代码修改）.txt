![image.png](https://pic.leetcode-cn.com/aa9c704a1ee50a71ba21453240f343c60328cd75c6b713949ce5852572864c40-image.png)

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

void Inorder(struct TreeNode*root,int *returnSize,int *res)
{
    if(!root)  return;
    Inorder(root->left,returnSize,res);
    res[(*returnSize)++]=root->val;
    Inorder(root->right,returnSize,res);
}


int TreeSize(struct TreeNode*root)
{
    if(!root)  return 0;
    return TreeSize(root->left)+TreeSize(root->right)+1;
}

int* inorderTraversal(struct TreeNode* root, int* returnSize){

int size=TreeSize(root);
int *res=malloc(sizeof(int)*size);
memset(res,0,size);
*returnSize=0;
Inorder(root,returnSize,res);
return res;
}
```
```
 #define MAXSIZE 1000
int TreeSize(struct TreeNode* root)
{
    if(!root)  return 0;
    return TreeSize(root->left)+TreeSize(root->right)+1;
}

int* inorderTraversal(struct TreeNode* root, int* returnSize){
    
    
    int size=TreeSize(root);
    //memset(res,0,size);

    int p=-1,index=0;
    if(!root){
        *returnSize=0;
        return NULL;
    } 
    struct TreeNode** src=malloc(sizeof(struct TreeNode*)*size); 
    int *res=malloc(sizeof(int)*size);
    while(root!=NULL||p!=-1)
    {
        while(root)
        {
        src[++p]=root;
        root=root->left;//一直往左走
        }

        if(p!=-1)
        {
        root=src[p--];
        res[index++]=root->val;
        root=root->right;
        }    
}
*returnSize =index;
return res;
}
```
