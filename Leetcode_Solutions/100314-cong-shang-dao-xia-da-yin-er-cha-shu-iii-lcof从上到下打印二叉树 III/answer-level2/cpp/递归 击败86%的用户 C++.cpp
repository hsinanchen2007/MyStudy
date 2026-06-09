### 解题思路
递归，并按层级奇偶分样式保存   （关注微信公众号'码农黑板报'获取更多题解）
![image.png](https://pic.leetcode-cn.com/ecf20521d19f03192a55db21e11ce36b6c0e535a47e271c8cfafb052258afbe6-image.png)


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
    vector<vector<int>> levelOrder(TreeNode* root) {
        int dep = 0;
        dep = depth(root, dep);
        vector<vector<int>> res(dep);
        dep = 0;
        dfs(res, root, dep);
        return res;
    }

    int depth(TreeNode* root, int dep) {
        if (root == NULL) {
            return dep;
        }
        return std::max(depth(root->left, dep+1), depth(root->right, dep+1));
    }

    void dfs(vector<vector<int>>& res, TreeNode* node, int dep) {
        if (node == NULL) {
            return;
        }
        if (dep % 2 == 1) {
            res[dep].insert(res[dep].begin(), node->val);
        } else {
            res[dep].push_back(node->val);
        }
        dfs(res, node->left, dep+1);
        dfs(res, node->right, dep+1);
    }
};
```