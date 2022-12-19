### 解题思路
经典的树形DP

### 代码

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int path = 0;
    int longestZigZag(TreeNode* root) {
        auto ans = dfs(root);
        return path;
    }

    pair<int, int> dfs(TreeNode* root)
    {
        if (root == nullptr) return {-1, -1};
        pair<int, int> ans = {0, 0};

        auto left = dfs(root -> left);
        auto right = dfs(root -> right);

        ans.first = left.second + 1;
        ans.second = right.first + 1;
        path = max(path, max(ans.first, ans.second));

        return ans;

    }
};
```