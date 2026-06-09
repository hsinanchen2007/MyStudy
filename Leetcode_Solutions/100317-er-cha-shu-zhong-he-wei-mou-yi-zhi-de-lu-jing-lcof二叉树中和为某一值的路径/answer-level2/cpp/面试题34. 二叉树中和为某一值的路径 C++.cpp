### 解题思路
DFS

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> result;
    void dfs(TreeNode *node, int sum, int target, vector<int> &buff)
    {
        if (node == nullptr) {
            return;
        }

        sum = sum + node->val;

        if (node->left == nullptr && node->right == nullptr && sum == target) {
            buff.push_back(node->val);
            result.push_back(buff);
            buff.pop_back();
            return;
        }

        buff.push_back(node->val);
        dfs(node->left, sum, target, buff);
        buff.pop_back();

        buff.push_back(node->val);
        dfs(node->right, sum, target, buff);
        buff.pop_back();

        return;
    }


    vector<vector<int>> pathSum(TreeNode *root, int sum)
    {
        result.clear();
        vector<int> buff;
        dfs(root, 0, sum, buff);

        return result;
    }
};
```