### 解题思路
简单递归，先序遍历。

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
        string tmp;
        helper(root, tmp, res);

        return res;
    }

    void helper(TreeNode* node, string tmp, vector<string>& res) {
        if (node) {
            tmp += to_string(node->val);
            if (!node->left && !node->right) {
                res.push_back(tmp);
            } else {
                helper(node->left, tmp+"->", res);
                helper(node->right, tmp+"->" ,res);
            }
        }
    }
};
```