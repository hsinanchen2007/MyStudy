用map存储，空间换时间
```
class Solution {
public:
    map<int, vector<int>> mmap;

    vector<vector<int>> findLeaves(TreeNode *root) {
        vector<vector<int>> res;
        if (!root) {
            return res;
        }
        postOrder(root);
        for (const auto& e***y : mmap) {
            res.push_back(e***y.second);
        }
        return res;
    }

    int postOrder(TreeNode *root) {
        int pos = 0;
        if (root->left) {
            pos = postOrder(root->left) + 1;
        }
        if (root->right) {
            pos = max(postOrder(root->right) + 1, pos);
        }
        mmap[pos].push_back(root->val);
        return pos;
    }
};
```