### 解题思路
两种递归都是非常经典的，最好自己都实现一遍

### 递归1代码

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
    int left=1,right=1;
    if(root==NULL)
        return 0;
    else
    {
        left+=maxDepth(root->left);
        right+=maxDepth(root->right);
    }
    return left>right?left:right;//很基础的判断
}
```
### 递归2代码
```
**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void maxdepthTraverse(struct TreeNode *root,int depth,int *maxdepth)
{
    if(root==NULL)
        return ;
    if(depth > *maxdepth)//递归过程中进行判断
        *maxdepth=depth;
    maxdepthTraverse(root->left,depth+1,maxdepth);
    maxdepthTraverse(root->right,depth+1,maxdepth);
//虽然会回溯但是不会起任何作用，这里递归是往里树下走树高度就+1，并作出判断
}
int maxDepth(struct TreeNode* root){
    int maxdep=0;
    maxdepthTraverse(root,1,&maxdep);
    return maxdep;
}
```
