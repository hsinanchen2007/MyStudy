### 解题思路
递归后翻转即可。
### 代码

```cpp
class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        Dfs(root, 0);
        return result;
    }

    void Dfs(TreeNode* root, int index) {
        if (root == nullptr) {
            return;
        }
        if (result.size() == index) {
            result.push_back({});
        }
        if (index % 2 == 0) {
            result[index].push_back(root->val);
        } else {
            result[index].insert(result[index].begin(), root->val);
        }
        Dfs(root->left, index + 1);
        Dfs(root->right, index + 1);
        return;
    }
};
```