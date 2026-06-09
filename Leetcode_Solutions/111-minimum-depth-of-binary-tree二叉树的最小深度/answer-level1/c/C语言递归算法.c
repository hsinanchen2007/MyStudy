分析情况
（1）根节点为NULL；返回0
（2）根节点（这里的根节点泛指所有节点）的两个孩子都为NULL；返回1
（3）根节点（这里的根节点泛指所有节点）的某一个孩子为NULL而另一个孩子不为空那在这里假设节点t的左孩子为NULL，右孩子不为空。我们知道题目问的是最近的叶子节点到根节点的距离为最短深度。那个此时节点t的左孩子为NULL是不存在叶子节点的，因此我们直接调用还是minDepth(t->right)+1;作为返回值进行递归。
```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int minDepth(struct TreeNode* root){
    if(!root)
        return 0;                 
    if(!root->left && !root->right)
        return 1;
    if(!root->left)
        return minDepth(root->right)+1;
    if(!root->right)
        return minDepth(root->left)+1;
      int  n = minDepth(root->left);
      int  m = minDepth(root->right);
    if(n>m)
        return m+1;
        return n+1;
}
```
