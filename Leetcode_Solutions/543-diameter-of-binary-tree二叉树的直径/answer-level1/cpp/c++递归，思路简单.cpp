### 解题思路
![批注 2020-03-04 172501.png](https://pic.leetcode-cn.com/e23e7506c4751a1cdf3ab4e7a2412ef9320c8d9b1d6f5243054c606150f1b287-%E6%89%B9%E6%B3%A8%202020-03-04%20172501.png)

思路非常简单，还是复用maxdepth求树高度的递归方式，额外维护一个全局变量radius记录直径的最大值
对于任意一个treenode，以它为根节点的子树里经过根节点的最长路径必然等于左子树高度加上右子树高度，radius就是比较经过每个treenode的最长路径，也就遍历了整棵树的所有节点的最长路径

### 代码

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int radius=0;
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)return 0;
        maxdepth(root);
        return radius;
    }
    int maxdepth(TreeNode* root){
        if(!root) return 0;
        int l=maxdepth(root->left);
        int r=maxdepth(root->right);
        if (l+r>radius) radius=l+r;
        return max(l,r)+1;
    }
};
```