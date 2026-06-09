### 解题思路
广度优先遍历，利用queue实现，但是在遍历每一层的时候要增加一层循环。

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        vector<TreeNode*> q;
        if (root != NULL) q.push_back(root);
        int tag = 0;
        while (!q.empty()) {
            int size = q.size();
            vector<int> tmp = {};
            if ((tag & 1) == 1) {
                for (int i = size - 1; i >= 0; i--) {
                    tmp.push_back(q[i]->val);
                }
            } else {
                for (int i = 0; i < size; i++) {
                    tmp.push_back(q[i]->val);
                }
            }
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.erase(q.begin());
                if (node->left) {
                    q.push_back(node->left);
                }
                if (node->right) {
                    q.push_back(node->right);
                }
            }
            tag++;
            res.push_back(tmp);
        }
        return res;
    }
};
```