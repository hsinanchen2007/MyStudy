```
class Solution {
    bool helper(TreeNode* left,TreeNode* right){
        if(!left && !right) return true; // 左右子树都不存在
        if(!left || !right || left->val != right->val) return false; //左右子树只有其一或值不相等
        return helper(left->left,right->right) && helper(left->right,right->left); //递归检查对称位置
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return helper(root->left,root->right);
    }
};
```
