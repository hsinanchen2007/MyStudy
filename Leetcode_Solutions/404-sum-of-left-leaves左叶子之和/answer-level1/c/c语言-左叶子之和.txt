### 解题思路
递归

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

struct TreeNode *pre=NULL;
int sumOfLeftLeaves(struct TreeNode* root){
    if(root==NULL)return 0;
    if(root->left==NULL&&root->right==NULL){
        if(pre!=NULL){
            if(pre->left==root)return root->val;
            else return 0;
        }
        else return 0;
    }
    else pre=root;
    return sumOfLeftLeaves( root->left)+sumOfLeftLeaves(root->right);
}
```