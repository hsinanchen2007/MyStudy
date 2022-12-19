- 自己竞赛时写的。写的比较多。后序遍历这样删除就不会影响遍历了。
```
class Solution {
public:
    vector<TreeNode*> res;
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> ut(to_delete.begin(), to_delete.end());
        post(root, ut);
        if (!ut.count(root->val)) res.push_back(root);
        else {
            if (root->left) res.push_back(root->left);
            if (root->right) res.push_back(root->right);
            root = nullptr;
        }
        return res;
    }
    
    void post(TreeNode* root, unordered_set<int>& ut) {
        if (!root) return;
        post(root->left, ut);
        post(root->right, ut);
        if (root->left && ut.count(root->left->val)) {
            if (root->left->left) res.push_back(root->left->left);
            if (root->left->right) res.push_back(root->left->right);
            root->left = nullptr;
        }
        if (root->right && ut.count(root->right->val)) {
            if (root->right->left) res.push_back(root->right->left);
            if (root->right->right) res.push_back(root->right->right);
            root->right = nullptr;
        }
    }
};
```

- 下面是大佬的代码。参考下。

```
class Solution {
public:
    vector<TreeNode*> res;
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> del(to_delete.begin(), to_delete.end());
        dfs(del, root, 1);
        return res;
    }
    void dfs(unordered_set<int>& del, TreeNode*& root, int flag) {
        if (!root) return;
        int found = del.count(root->val);
        dfs(del, root->left, found);
        dfs(del, root->right, found);
        if (!found && flag) res.push_back(root);
        if (found) root = nullptr;
    }
};
```
