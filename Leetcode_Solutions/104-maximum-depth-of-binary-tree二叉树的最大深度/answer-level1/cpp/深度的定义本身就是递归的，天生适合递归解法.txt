```
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
    int maxDepth(TreeNode* root) {
        return traverse(root);
    }
    
    int traverse(TreeNode* root) {
        // 返回树的深度
        // 当前树的深度 = max{deep(root->left}, deep(root->right)} + 1;
        // 即 等于左子树的深度与右子树的深度的较大者，再算上根节点(depth+1)
        if (!root) return 0;
        
        int dep1 = traverse(root->left);
        int dep2 = traverse(root->right);
        
        int dep = dep1>dep2 ? dep1 : dep2;
        return dep+1;
    }
};
```
