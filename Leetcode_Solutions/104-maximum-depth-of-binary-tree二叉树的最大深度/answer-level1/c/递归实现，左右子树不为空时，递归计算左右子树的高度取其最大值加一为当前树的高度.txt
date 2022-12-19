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
    int left_depth=0,right_depth=0,depth=0;
    if(root==NULL) return 0;
    if(root->left!=NULL) left_depth = maxDepth(root->left);
    if(root->right!=NULL) right_depth = maxDepth(root->right);
    depth = left_depth>right_depth?(left_depth+1):(right_depth+1);
    return depth;
}
```