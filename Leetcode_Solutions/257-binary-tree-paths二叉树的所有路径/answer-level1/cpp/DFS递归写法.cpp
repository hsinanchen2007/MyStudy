``` c++
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (!root) return res;
        
        string s;
        s += to_string(root->val);
        
        if(!root->left&&!root->right) {
            res.push_back(s);
        }
        
        
        if (root->left) {
            vector<string> left = binaryTreePaths(root->left);
            for (int i = 0; i < left.size(); ++i) {
                res.push_back(s + "->" + left[i]);
            }
        }

        if (root->right) {
            vector<string> right = binaryTreePaths(root->right);
            for (int j = 0; j < right.size(); ++j) {
                res.push_back(s + "->" + right[j]);
            }
        }
        
        return res;       
    }
   
    
};
```
