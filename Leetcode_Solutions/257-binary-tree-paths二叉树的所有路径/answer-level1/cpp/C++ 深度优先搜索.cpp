### 解题思路
深度优先搜索，用string记录路径

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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        std::string str = "";
        dfs(res, str, root);
        return res;
    }

    void dfs(vector<string>& res, string str, TreeNode* node) {
        if (node == NULL) {
            return;
        }
        if (node->left == NULL && node->right == NULL) {
            str += std::to_string(node->val);
            res.push_back(str);
            return;
        }
        str = str + std::to_string(node->val) + "->";
        dfs(res, str, node->left);
        dfs(res, str, node->right);
    }
};
```
![码农黑板报.png](https://pic.leetcode-cn.com/27df4b965401f0da621fdd899b15fd97b0ad93d8737c5ede51508144d3d78798-%E7%A0%81%E5%86%9C%E9%BB%91%E6%9D%BF%E6%8A%A5.png)
