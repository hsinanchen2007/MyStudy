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
if(!root)   return;
if(root->left){     //右子树存在时，对其进行操作
struct TreeNode*p,*q,*p1;
p=root->left;
q=root->right;
root->left=NULL;
root->right=p;
p1=p;
while(p1&&p1->right){
    p1=p1->right;
}
p1->right=q;
}
flatten(root->right);
}
```