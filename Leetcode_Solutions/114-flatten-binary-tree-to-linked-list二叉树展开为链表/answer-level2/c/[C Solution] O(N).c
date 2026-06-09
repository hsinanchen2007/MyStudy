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
    
    while(root != NULL){
        if(root->left != NULL){
            struct TreeNode* tmp = root-> right;
            root->right = root->left;
            root->left = NULL;
            root = root->right;
            struct TreeNode* tmp2 = root;
            while(tmp2->right != NULL){
                tmp2 = tmp2->right;
            }
            tmp2->right = tmp;
        }else{
            root = root->right;
        }
    }
}
```