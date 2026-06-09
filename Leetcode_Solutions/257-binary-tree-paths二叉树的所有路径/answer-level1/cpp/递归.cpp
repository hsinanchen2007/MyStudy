```
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(root == NULL)
            return res;
        search(root, "", res);
        return res;
    }
    void search(TreeNode* root, string s, vector<string>& res)
    {
        string curs = s + to_string(root->val) ;
        if (root == NULL)
            return;
        else if(root->left == NULL && root->right == NULL)
        {
            return res.push_back(curs);
        }
        if(root->left != NULL)
        {
            search(root->left, curs + "->", res);
        }
        if(root->right != NULL)
        {
            search(root->right, curs + "->", res);
        }
        return;
    }
};
```
