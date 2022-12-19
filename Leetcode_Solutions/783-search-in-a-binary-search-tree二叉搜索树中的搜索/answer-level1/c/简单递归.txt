### 解题思路
简单递归。

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

struct TreeNode* result;
struct TreeNode* searchBST(struct TreeNode* root, int val){
    if(root==NULL)
    return NULL;
    if(root->val==val)
    return root;
    if(root->val>val)
    result=searchBST(root->left,val);
    if(root->val<val)
    result=searchBST(root->right,val);
    return result;
}
```