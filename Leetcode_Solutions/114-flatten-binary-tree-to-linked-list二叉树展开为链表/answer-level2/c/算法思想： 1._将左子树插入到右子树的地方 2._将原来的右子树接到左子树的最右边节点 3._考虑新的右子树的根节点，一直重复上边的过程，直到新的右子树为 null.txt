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


void flatten(struct TreeNode* root){
    if(root==NULL || (root->left==NULL && root->right==NULL)){
        return;
    }
     struct TreeNode *parent = NULL;
     if(root->left != NULL){
         parent = root->left;
         while(parent->right) parent=parent->right;
         parent->right = root->right;
         root->right = root->left;
         root->left=NULL;
     }
     flatten(root->right);
}
```