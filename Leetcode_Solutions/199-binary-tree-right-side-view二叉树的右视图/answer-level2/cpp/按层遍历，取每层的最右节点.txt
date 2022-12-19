``` cpp
vector<int> rightSideView(TreeNode* root) {
    vector<int> res;
    if (root == nullptr) return res;
    queue<TreeNode*> q;
    q.emplace(root);
    while (!q.empty()) {
        res.emplace_back(q.front()->val);
        size_t n = q.size();
        for (size_t i = 0; i < n; i++) {
            if (q.front()->right != nullptr) q.emplace(q.front()->right);
            if (q.front()->left != nullptr) q.emplace(q.front()->left);
            q.pop();
        }
    }
    return res;
}
```
