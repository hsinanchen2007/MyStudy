思路：回溯

1. 改变状态：将当前节点增加至 path
2. 操作/递归：若符合条件则添加至 res，否则递归进入左右子树
3. 恢复状态：通过记录初始长度，操作完成后对新增长度进行擦除，以实现恢复状态
  
```CPP
class Solution {
    string path;
    vector<string> res;
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        backtrack(root);
        return res;
    }
    void backtrack(TreeNode* root) {
        if (!root) return;
        int len = path.size();                          // 记录初始状态（记住长度）
        path += (path.empty() ? "" : "->") + to_string(root->val);  // 改变状态（增加长度）
        if (!root->left && !root->right) res.push_back(path);       // 符合条件则添加至 res
        else backtrack(root->left), backtrack(root->right);         // 否则递归进入左右子树
        path.erase(path.begin() + len, path.end());     // 恢复初始状态（擦去新增的长度）
    }
};
```
