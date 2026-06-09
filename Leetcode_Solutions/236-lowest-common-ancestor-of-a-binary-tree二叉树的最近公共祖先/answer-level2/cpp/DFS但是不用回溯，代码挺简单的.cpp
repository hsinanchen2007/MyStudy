  思路就是用两个状态位表示是否在这棵树能过够找到两个目标节点，然后通过递归解决该问题，为了编程简洁一点直接用`int`的后两位表示，同时递归的实现也能够保证得到的父节点深度最大。
```
/**
class Solution {
public:
    TreeNode *p = nullptr, *q = nullptr, *res = nullptr;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        this->p = p; this->q = q;
        findTarget(root);
        return res;
    }
    
    int findTarget(TreeNode* root) {
        int ans = 0;
        if (root == nullptr) return ans;
        if (root == p) ans += 1;//结果为两个状态位，表示在这颗子树是否能够找到节点p, q
        else if (root == q) ans += 2;
        ans = ans | findTarget(root->left) | findTarget(root->right);
        if (ans == 3 && res == nullptr) res = root;
        return ans;
    }
};
```

