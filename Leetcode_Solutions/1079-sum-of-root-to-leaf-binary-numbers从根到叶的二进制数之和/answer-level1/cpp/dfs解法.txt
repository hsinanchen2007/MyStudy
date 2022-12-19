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
    int sumRootToLeaf(TreeNode* root) {

        if (!root) return 0;

        int ans = 0;
        function<void(TreeNode*, int)> dfs = [&](TreeNode* node, int num) {
            if (!node) return;
            // num = num * 2 + node->val; // 这样写太普通了...
            num = num << 1 | node->val;  // ingenious 精妙... 
            if (!node->left && !node->right) {
                ans += num;
                return;
            }

            dfs(node->left, num);
            dfs(node->right, num);
        };

        dfs(root, 0);
        return ans;
    }
};
```