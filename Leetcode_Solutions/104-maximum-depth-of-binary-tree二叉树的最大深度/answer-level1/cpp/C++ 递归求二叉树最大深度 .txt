C++ 神奇的递归  
写下自己的理解：
第一步：
二叉树的最大深度=max(左边二叉树的深度，右边二叉树的深度) + root节点深度1；
第二步：
左边二叉树的深度的解法可以把左边二叉树当做根节点，那么求法就是第一步；
第三步：
右边二叉树的深度的解法可以把右边二叉树当做根节点，求法也是第一步；
所以可以构成递归了。
  
```cpp
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int len1 = maxDepth(root->left);
        int len2 = maxDepth(root->right);
        return max(len1, len2) + 1;
    }
};
```
