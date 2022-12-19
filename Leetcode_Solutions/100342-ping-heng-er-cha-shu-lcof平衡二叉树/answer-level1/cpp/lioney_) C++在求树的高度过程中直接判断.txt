```
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        bool res = true;
        heigth(root, res);
        return res;
    }
    int heigth(TreeNode* root, bool& res) {
        if(!root) return 0;
        int left = heigth(root->left, res) + 1;
        int right = heigth(root->right, res) + 1;
        if(abs(left-right) > 1) res = false;
        return max(left, right);
    }
};
```
