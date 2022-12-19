题目也没说不得修改原始树，所以可以直接把子树的高度写入节点的val属性中，这样一个递归搞定
```cpp
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;
        if (!isBalanced(root->left)) return false;
        if (!isBalanced(root->right)) return false;
        int l = 0, r = 0;
        if (root->left != nullptr) l = root->left->val;
        if (root->right != nullptr) r = root->right->val;
        root->val = max(l, r) + 1;  //把当前子树的高度信息写入节点的val中
        return abs(l - r) <= 1;
    }
};
```