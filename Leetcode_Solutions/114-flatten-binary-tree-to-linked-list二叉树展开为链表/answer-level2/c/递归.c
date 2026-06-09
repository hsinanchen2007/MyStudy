### 解题思路
才开始做不对，居然一直是因为忘了root->left=NULL 气死了

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
    if(root==NULL) return ;
    if(!root->left&&!root->right) return;
    flatten(root->right);
    flatten(root->left);
    if(root->left){
        struct TreeNode *p;
        p=root->left;
        while(p->right){
            p=p->right;
        }
        p->right=root->right;
        root->right=root->left;
        root->left=NULL;
    }
}
```