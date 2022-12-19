### 解题思路
直接用个队列往里面塞每次节点的左右子节点就行。。。

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
        if (root == NULL) {
            return {};
        }
        queue<TreeNode*> que;
        vector<int> res;
        que.push(root);
        while (!que.empty()) {
            auto t = que.front();
            que.pop();
            res.emplace_back(t->val);
            if (t->left != NULL) {
                que.push(t->left);
            }
            if (t->right != NULL) {
                que.push(t->right);
            }
        }
        return res;
    }
};
```