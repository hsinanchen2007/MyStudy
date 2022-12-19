### 解题思路
执行用时:16 ms, 在所有 C++ 提交中击败了 65.28% 的用户
内存消耗:16.9 MB, 在所有 C++ 提交中击败了 100.00% 的用户。

用res记录路径结果数组，path和pathSum分别记录路径和当前路径和，注意递归边界条件，回溯pathSum和path数组。

### 代码

```cpp
class Solution {
    vector<vector<int>> res;
public:
    void dfs(TreeNode* root, vector<int>& path, int sum, int pathSum){
        path.push_back(root->val);
        pathSum += root->val;
        if(!root->left && !root->right){
            if(pathSum == sum) res.push_back(path);
            pathSum -= root->val;
            path.pop_back();
            return;
        }else {
            if(root->left){
                dfs(root->left, path, sum, pathSum);
            }
            if(root->right){
                dfs(root->right, path, sum, pathSum);
            }
            pathSum -= root->val;
            path.pop_back();
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(!root) return {};
        vector<int> path;
        dfs(root, path, sum, 0);
        return res;
    }
};



```