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
bool equalTree(struct TreeNode*root1,struct TreeNode*root2){
    if(root1==NULL&&root2==NULL)
    return true;
    if(root1==NULL||root2==NULL)
    return false;
    if(root1->val!=root2->val)
    return false;
    return equalTree(root1->left,root2->right)&&equalTree(root1->right,root2->left);
}
bool isSymmetric(struct TreeNode* root){
return equalTree(root,root);
}
```