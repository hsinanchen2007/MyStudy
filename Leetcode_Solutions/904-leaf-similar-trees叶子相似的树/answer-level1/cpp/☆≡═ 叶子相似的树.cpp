1. 用栈先序遍历二叉树得到叶子。
2. 比较叶子是否相同。
```
class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        return get_leaf(root1) == get_leaf(root2);
    }
private:
    vector<int> get_leaf(TreeNode* root) {
        vector<int> leaf;
        stack<const TreeNode*> s;
        if (root) s.push(root);
        while (!s.empty()) {
            const TreeNode* p = s.top();
            s.pop();
            if (!p->left && !p->right) leaf.push_back(p->val);
            if (p->right) s.push(p->right);
            if (p->left) s.push(p->left);
        }
        return leaf;
    }
};
```
