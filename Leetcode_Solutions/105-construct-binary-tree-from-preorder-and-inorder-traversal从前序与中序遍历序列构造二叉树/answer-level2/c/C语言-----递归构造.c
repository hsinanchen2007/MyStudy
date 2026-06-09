### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
struct TreeNode*s;
int*p;int k;
if(preorderSize<=0)
return NULL;
s=(struct TreeNode*)malloc(sizeof(struct TreeNode));
s->val=preorder[0];
for(k=0;k<inorderSize;k++)
if(inorder[k]==preorder[0])
break;
s->left=buildTree(preorder+1,k,inorder,k);
s->right=buildTree(preorder+k+1,preorderSize-k-1,inorder+k+1,inorderSize-k-1);
return s;
}
```