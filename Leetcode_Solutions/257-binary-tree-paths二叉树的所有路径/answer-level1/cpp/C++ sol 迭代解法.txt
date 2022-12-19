### 解题思路
迭代解法，比较简答，是先序遍历。

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
        if (!root) return {};

        vector<string> res;
        stack<pair<TreeNode*, string>> s({ {root, ""} });
        while (!s.empty()) {
            auto it = s.top(); s.pop();
            TreeNode* node = it.first;
            string path = it.second + to_string(node->val);

            if (!node->left && !node->right) {
                res.push_back(path);
            }
            
            if (node->right) s.push({node->right, path+"->"});
            if (node->left) s.push({node->left, path+"->"});
        }

        return res;
    }
};
```