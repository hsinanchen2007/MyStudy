回溯法核心思想：更改状态 -> 操作/递归 -> 恢复状态
  
目标条件分解：
1. 题中已说明叶子节点是指没有子节点的节点。即左右节点均为 NULL 时，满足`叶子节点`条件
2. 每经过 1 个节点，在路径和上减去该节点 val 值，当 sum 为 0 时，满足`目标和`条件
3. 同时满足以上条件时，将 path 添加到 res，否则进行回溯
  
```
class Solution {
    vector<int> path;
    vector<vector<int>> res;
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        backtrack (root, sum);
        return res;
    }
    void backtrack(TreeNode* root, int sum) {
        if (!root) return;
        path.push_back(root->val);
        sum -= root->val;
        if (!root->left && !root->right && !sum) res.push_back(path);
        else backtrack(root->left, sum) , backtrack(root->right, sum);
        path.pop_back();
        sum += root->val;
    }
};
```
