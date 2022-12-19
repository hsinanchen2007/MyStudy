### 解题思路
深度优先搜索
![image.png](https://pic.leetcode-cn.com/df794a81f731578787c81ee7075b35d1e118bbe03cc730030d021cdecd7f2a5b-image.png)


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
    bool hasPathSum(TreeNode* root, int sum) {
        vector<int> res;
        int count = 0;
        dfs(res, count, root);
        for (int i = 0; i < res.size(); i++) {
            if (res[i] == sum) {
                return true;
            }
        }
        return false;
    }

    void dfs(vector<int>& res, int count, TreeNode* node) {
        if (node == NULL) {
            return;
        }
        if (node->left == NULL && node->right == NULL) {
            count += node->val;
            res.push_back(count);
            return;
        }
        count += node->val;
        dfs(res, count, node->left);
        dfs(res, count, node->right);
    }
};
```
![码农黑板报.png](https://pic.leetcode-cn.com/965e9f32d71618a09fd9410e012791fbd011b8b1a5342dbc76b47dfa2c61ebc3-%E7%A0%81%E5%86%9C%E9%BB%91%E6%9D%BF%E6%8A%A5.png)
