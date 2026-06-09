### 解题思路
直接用队列存储没一行的节点，然后导出到数组，然后继续push进下一行的节点到队列中就行了。

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
        if (root == NULL) return {};
        queue<TreeNode*> que;
        vector<vector<int>> res;
        que.push(root);
        while(!que.empty()) {
            long size = que.size();
            vector<int> tmp;
            for (int i=0; i<size; i++) {
                auto v = que.front();
                que.pop();
                tmp.emplace_back(v->val);
                if (v->left != NULL) que.push(v->left);
                if (v->right != NULL) que.push(v->right);
            }
            res.emplace_back(tmp);
        }
        return res;
    }
};
```