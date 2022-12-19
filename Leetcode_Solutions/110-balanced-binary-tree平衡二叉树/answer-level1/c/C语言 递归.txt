判断每个节点的左右子节点深度和求二叉树的最大深度比较类似。
分情况：
（1）：当根节点为NULL，返回ture；
（2）；将问题分解，求根节点左右孩子深度转化为：求左孩子**左右孩子深度**和右孩子的**左右孩子深度**。于是做出一个求最大深度的函数int Maxdepth(struct TreeNode* t)。这里分析返回true和返回false的情况。（1）Maxdepth(root->left)-Maxdepth(root->right)大于1或者小于-1返回fasle。（2）而满足（!root->left && !root->right）则返回true。代码如下
```
int depth(struct TreeNode* root);
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool isBalanced(struct TreeNode* root){
    if(!root)
        return true;
    if(!root->left && !root->right)
        return true;
    if(depth(root->left)-depth(root->right) > 1 || depth(root->left)-depth(root->right) <-1)
             return false;
    return isBalanced(root->left) && isBalanced(root->right);
}

int depth(struct TreeNode* root){
    if(!root)
        return 0;
    int n = depth(root->left);
    int m = depth(root->right);
    if(m>n)
        return m+1;
    return n+1;
}
代码块
```
