C++ 递归深度优先，24ms(92%), 21.5MB(63%)

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
        int idx = 0;
        int res = 0;
        TreeNode* parent;
        
        dfs(root, idx, res, k);
        
        return res;
    }
    
    void dfs(TreeNode* node, int& idx, int &res, int& k)
    {
        if (res || !node)
        {
            return;
        }
        
        dfs(node->left, idx, res, k);
        
        if (++idx == k)
        {
            res = node->val;
        }
        
        dfs(node->right, idx, res, k);
    }
};
```
