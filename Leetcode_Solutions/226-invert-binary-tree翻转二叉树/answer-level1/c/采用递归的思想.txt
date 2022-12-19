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


struct TreeNode* invertTree(struct TreeNode* root){
    if(root==NULL){
        return NULL;
    }
       struct TreeNode* right = invertTree(root->right);
       struct TreeNode* left = invertTree(root->left);
        root->left = right;  //  交换左、右孩子结点
        root->right = left;
    return root;
}
```