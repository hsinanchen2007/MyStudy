### 解题思路
//以root为根节点的树中包含p和q，则返回它们的最低公共祖先
//以root为根节点的树中只包含p或q,则返回p或q
//以root为根节点的树中不包含p和q，则返回NULL

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
        if(!root|| root==p || root==q)
		    return root;
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);
        
        if(!left)
            return right;
        if(!right)
            return left;
        return root;
    }
};
```