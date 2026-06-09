### 递归
```c++
bool isValidBST(TreeNode *root, int64_t low, int64_t high) {
    if (!root) {
        return true;
    }
    if (root->val >= high || root->val <= low) {
        return false;
    }
    bool valid = true;
    if (root->left) {
        valid &= isValidBST(root->left, low, root->val);
    }
    if (root->right) {
        valid &= isValidBST(root->right, root->val, high);
    }
    return valid;
}

bool isValidBST_v1(TreeNode* root) {
    int64_t max_value = (int64_t)INT_MAX + 1;
    int64_t min_value = (int64_t)INT_MIN - 1;
    return isValidBST(root, min_value, max_value);
}
```

### 迭代
```c++
bool isValidBST(TreeNode* root) {
    std::stack<TreeNode*> s;
    int64_t last = (int64_t)INT_MIN - 1;
    while (!s.empty() || root) {
        if (root) {
            s.push(root);
            root = root->left;
        }
        else {
            root = s.top();
            s.pop();
            if (root->val <= last) {
                return false;
            }
            last = root->val;
            root = root->right;
        }
    }
    return true;
}
```