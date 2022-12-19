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
    
    void preAccess(TreeNode* t, string & str)
    {
        if(t == NULL) return;
        str += to_string(t->val);
        if(t->left || t->right)
        {
            str += "(";
            preAccess(t->left, str);
            str += ")";
        }
        if(t->right)
        {
            str += "(";
            preAccess(t->right, str);
            str += ")";
        }
    }
    
    string tree2str(TreeNode* t) {
        string res = "";
        preAccess(t, res);
        return res;
    }
};
```