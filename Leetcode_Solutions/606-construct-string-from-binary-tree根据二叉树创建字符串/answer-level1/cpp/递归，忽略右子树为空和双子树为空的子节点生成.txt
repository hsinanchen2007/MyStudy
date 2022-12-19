```
class Solution {
public:
    string tree2str(TreeNode* t) {
        if(t == NULL)
        {
            return "";
        }
        if(t->left == NULL && t->right == NULL)
        {
            return to_string(t->val);
        }
        string ret = to_string(t->val);
        ret += "(" + tree2str(t->left) + ")";
        if(t->right != NULL)
        {
            ret += "(" + tree2str(t->right) + ")";
        }
        return ret;
    }
};
```
