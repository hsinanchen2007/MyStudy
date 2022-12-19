### 解题思路
此处撰写解题思路

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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {

        vector<vector<int>> ans;
        if (!root) return ans;

        // dfs 深度优先搜索
        function<void(TreeNode*, vector<int>)> dfs 
                = [&](TreeNode* node, vector<int> nums) {

            if (!node) return;
            nums.emplace_back(node->val);

            if (!node->left && !node->right 
                    && accumulate(nums.begin(), nums.end(), 0) == sum) {
                ans.emplace_back(nums);
                return;
            }

            dfs(node->left, nums);
            dfs(node->right, nums);
        };

        dfs(root, {});
        return ans;
    }
};
```