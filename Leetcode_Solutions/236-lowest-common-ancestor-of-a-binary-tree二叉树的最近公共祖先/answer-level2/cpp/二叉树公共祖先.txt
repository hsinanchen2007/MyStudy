### 解题思路
1.若p和q位于同一条路径，即p==root或q==root，那么公共祖先就是最上面那个，也就是root
2.若不是，又可以分三种情况
1)p,q位于root的左边，那么结果就是递归调用root->left,p,q的结果
2)p,q为于root的右边，参考1
3)p,q分列两边，那么结果就是root

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        // if(left && left != p && left != q) return left;
        TreeNode* right = lowestCommonAncestor(root->right,p,q);
        if(left && right) return root;//p,q分别位于两边，那么left和right其实就是p和q
        return left ? left : right;
    }
};
```