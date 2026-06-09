额，没啥想法只能用笨方法解题
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
        vector<int> res;
        norder(root, res);
        
        sort(res.begin(), res.end());
        return res[k - 1];
    }
    void norder(TreeNode* root, vector<int>& vec)
    {
        if (!root) return;
        
        norder(root->left, vec);
        
        vec.push_back(root->val);
        
        norder(root->right, vec); 
        
    }
};
```
