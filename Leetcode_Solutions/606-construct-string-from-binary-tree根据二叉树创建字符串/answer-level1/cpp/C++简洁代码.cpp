```
class Solution {
public:
    string ans = "";
    string tree2str(TreeNode* t) {
        if(!t) return "";
        ans = ans+ to_string(t->val);
        if(t->left||(t->left ==NULL && t->right)){
            ans.push_back('(');
            tree2str(t->left);
            ans.push_back(')');
        }
        if(t->right){
            ans.push_back('(');
            tree2str(t->right);
            ans.push_back(')');
        }
        return ans;
    }
};
```
