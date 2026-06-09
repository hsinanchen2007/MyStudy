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


struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize){
struct TreeNode*s;
int k;
if(inorderSize<=0)
return NULL;
s=(struct TreeNode*)malloc(sizeof(struct TreeNode));
s->val=postorder[postorderSize-1];
for(k=0;k<inorderSize;k++)
if(inorder[k]==postorder[postorderSize-1])
break;
s->left=buildTree(inorder,k,postorder,k);
s->right=buildTree(inorder+k+1,inorderSize-k-1,postorder+k,postorderSize-k-1);
return s;
}
```