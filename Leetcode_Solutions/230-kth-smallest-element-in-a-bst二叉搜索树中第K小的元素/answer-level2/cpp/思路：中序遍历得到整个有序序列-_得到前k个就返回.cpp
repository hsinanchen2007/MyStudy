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
    int kthSmallest(TreeNode* root, int k) {
        return inOrder(root, k)->val;
    }
    
    TreeNode* inOrder(TreeNode* root, int& k) {
        if (!root) return root;
        
        auto* node1 = inOrder(root->left, k);
        if (--k == 0) return root;
        auto* node2 = inOrder(root->right, k);
        
        if (node1) return node1;
        if (node2) return node2;
        return nullptr;
    }
    
};
```
