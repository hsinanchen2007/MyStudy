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


int maxDepth(struct TreeNode* root){
    int ldep,rdep;
    ldep = rdep =0;
    if(root==NULL)
     return 0;
     if(root->left){
        ldep = maxDepth(root->left);
     }
     if(root->right){
         rdep = maxDepth(root->right);
     }
     if(rdep>ldep){
         return rdep+1;
     }
     else{
         return ldep+1;
     }
    
}
```