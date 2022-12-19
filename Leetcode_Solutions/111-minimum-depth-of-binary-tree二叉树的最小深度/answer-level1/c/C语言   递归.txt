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


int minDepth(struct TreeNode* root){
if(root==NULL)
return NULL;
if(root->right==NULL&&root->left==NULL)
return 1;
if(root->right==NULL)
return minDepth(root->left)+1;
if(root->left==NULL)
return minDepth(root->right)+1;
int left=minDepth(root->left);
int right=minDepth(root->right);
return left<right?left+1:right+1;
}
```