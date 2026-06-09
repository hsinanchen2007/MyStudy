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
#define MAX(a,b) (a) > (b) ? (a) : (b)
int hfun(struct TreeNode* root)
{
    if(root == NULL)
        return 0;
    int leftheight = 1;
    int rightheight = 1;
    if(root->left != NULL)
        leftheight += hfun(root->left);
    if(root->right != NULL)
        rightheight += hfun(root->right);
    
    return MAX(leftheight,rightheight);    
    
}
bool isBalanced(struct TreeNode* root){
if(!root) return true;
if(root->left == NULL && root->right == NULL) return true;
//printf("%d %d %d",hfun(root->right),hfun(root->left),abs(hfun(root->right)-hfun(root->left)));
if(abs(hfun(root->right)-hfun(root->left))<=1){
    return isBalanced(root->right)&&isBalanced(root->left);
}
else return false;
}
```