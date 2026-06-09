### 解题思路
使用一个函数求一个结点的最大深度（该函数使用递归），然后在isBalanced函数中使用递归进行判断。因为实际不需要得到每个节点的深度，因此这个方法还有优化的空间。好处是代码简洁易懂。执行用时：8ms；内存消耗：8.7M。

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
unsigned int maxDepth(struct TreeNode* root);

bool isBalanced(struct TreeNode* root){
    if(root==NULL)return true;
    if(root->left==NULL&&root->right==NULL)return true;
    if(abs(maxDepth(root->left)-maxDepth(root->right))>1)return false;
    else return (isBalanced(root->left)&&isBalanced(root->right));
}
//使用递归得到当前节点的最大深度
unsigned int maxDepth(struct TreeNode* root){
    if(root==NULL)return 0;
    if(root->left==NULL&&root->right==NULL)return 1;
    unsigned int n_left=maxDepth(root->left)+1;
    unsigned int n_right=maxDepth(root->right)+1;
    return (n_left>n_right?n_left:n_right);
}
```