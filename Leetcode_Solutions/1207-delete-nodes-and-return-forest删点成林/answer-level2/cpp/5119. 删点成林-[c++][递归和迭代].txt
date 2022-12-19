
- 版本一：递归，后序遍历

```cpp
class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> res;
        set<int> delset(to_delete.begin(), to_delete.end());
        if (root && !delset.count(root->val)) {
            res.push_back(root);
        }
        postorder(root, nullptr, delset, res);
        return res;
    }
    
    void postorder(TreeNode* node, TreeNode* parent, set<int>& delset, vector<TreeNode*>& res) {
        if (!node) return;
        
        postorder(node->left, node, delset, res);
        postorder(node->right, node, delset, res);
        
        if (delset.count(node->val)) {
            if (node->left && !delset.count(node->left->val)) res.push_back(node->left);
            if (node->right && !delset.count(node->right->val)) res.push_back(node->right);
            if (parent && parent->left == node) parent->left = nullptr;
            if (parent && parent->right == node) parent->right = nullptr;
        }
    }
};
```

- 版本二：迭代，层次遍历。把要删除的节点标记为 0.

```cpp
class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> res;
        if (!root) return res;
        if (to_delete.empty()) return res;
        queue<TreeNode*> q;
        q.push(root);
        set<int> delset(to_delete.begin(), to_delete.end());
        if (delset.count(root->val) == 0) {
            res.push_back(root);
        }
        while (!q.empty() && !delset.empty()) {
            auto node = q.front();
            q.pop();
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
            auto it = delset.find(node->val);
            if (it != delset.end()) {
                node->val = 0;
                if (node->left && !delset.count(node->left->val)) res.push_back(node->left);
                if (node->right && !delset.count(node->right->val)) res.push_back(node->right);
                node->left = nullptr;
                node->right = nullptr;
                delset.erase(it);
            }
        }
        
        for (auto tree : res) {
            queue<TreeNode*> q;
            q.push(tree);
            while (!q.empty()) {
                auto node = q.front();
                q.pop();
                if (node->left) {
                    if (node->left->val == 0) node->left = nullptr;
                    else q.push(node->left);
                }
                if (node->right) {
                    if (node->right->val == 0) node->right = nullptr;
                    else q.push(node->right);
                }
            }
        }
        return res;
    }
};
```

