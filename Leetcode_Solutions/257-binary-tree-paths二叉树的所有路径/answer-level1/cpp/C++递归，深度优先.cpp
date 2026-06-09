```
class Solution {
public:
    vector<string> vs;
    void findTreePaths(TreeNode* root, string s)
    {
        if(!root) return;
        else if(!root->left && !root->right)
        {
            s += to_string(root->val);
            vs.push_back(s);
            return;
        }
        else{
             s += to_string(root->val);
             s += "->";
            findTreePaths(root->left, s);
            findTreePaths(root->right, s);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string s;
        findTreePaths(root,s);
        return vs;
    }
};
```
