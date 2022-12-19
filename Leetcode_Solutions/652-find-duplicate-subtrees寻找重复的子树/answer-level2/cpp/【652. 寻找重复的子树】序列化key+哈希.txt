## 思路
后序遍历，将每个节点的后序遍历的数字串作为key，自底向上，如果遇到value值为1，则加入到结果集中。
### 代码
```
class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> vec;
        unordered_map<string, int> umap;
        helper(root, vec, umap);
        return vec;
    }

    string helper(TreeNode *root, vector<TreeNode*> &vec, unordered_map<string, int> &umap) {
        if (!root) return "#";
        string str = to_string(root->val) + helper(root->left, vec, umap) + helper(root->right, vec, umap);
        if (umap[str] == 1) {
            vec.push_back(root);
        }
        ++umap[str];
        return str;
    }
};
```
