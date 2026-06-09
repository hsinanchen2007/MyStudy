```
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int re = 0;
        if(root == nullptr) return 0;
        solve(root, re, 0);
        return re;
    }
    void solve(TreeNode *root, int &re, int num){
        int tmp = num * 10 + root->val;
        if(root->left == nullptr && root->right == nullptr) 
            re += tmp;
        if(root->left != nullptr)solve(root->left, re, tmp);
        if(root->right != nullptr) solve(root->right, re, tmp);
    }
};
```
