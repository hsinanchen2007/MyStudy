### 解题思路
迭代
![image.png](https://pic.leetcode-cn.com/d917f041bd35cd2e3eec1feea53e0eb4e3491f4e6305a8ad7b42f3b24a9998ae-image.png)


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
    vector<int> levelOrder(TreeNode* root) {
        vector<TreeNode*> nodes;
        vector<int> res;
        if (root == NULL) {
            return res;
        }
        nodes.push_back(root);
        while (!nodes.empty()) {
            TreeNode* node = nodes.front();
            res.push_back(node->val);
            if (node->left) {
                nodes.push_back(node->left);
            }
            if (node->right) {
                nodes.push_back(node->right);
            }
            nodes.erase(nodes.begin());
        }
        return res;
    }
};
```