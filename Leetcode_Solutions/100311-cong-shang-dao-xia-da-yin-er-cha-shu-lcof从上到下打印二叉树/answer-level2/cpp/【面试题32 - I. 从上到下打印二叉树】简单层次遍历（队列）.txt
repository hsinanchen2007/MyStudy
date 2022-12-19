## 思路

### 代码

```cpp
class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        vector<int> res;
        if (root) {
            queue<TreeNode*> que;
            que.push(root);
            while (!que.empty()) {
                TreeNode *node = que.front();
                que.pop();
                res.push_back(node->val);
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
        }
        return res;
    }
};
```