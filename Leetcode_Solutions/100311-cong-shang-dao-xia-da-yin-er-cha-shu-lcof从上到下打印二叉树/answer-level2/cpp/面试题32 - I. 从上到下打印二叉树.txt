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
    vector<int> levelOrder(TreeNode* root) {
        
        vector<int> v;
        if (root == NULL)
            return v;

        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode * tmp = q.front();
            v.push_back(tmp->val);
            q.pop();
            if (tmp->left)
                q.push(tmp->left);
            if (tmp->right)
                q.push(tmp->right);
        }
        
        return v;
            
    }
};
```