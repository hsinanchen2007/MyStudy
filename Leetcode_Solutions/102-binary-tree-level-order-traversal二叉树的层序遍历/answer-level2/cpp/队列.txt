### 解题思路
queue<pair<TreeNode*, int>>分别保存当前的节点和行。 
按照层次遍历的顺序，将当前一层的节点值保存在vector中，并同时将其孩子节点入队。

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
        queue<pair<TreeNode*, int>> q;
        vector<vector<int>> vec;
        int line = 1, oldline = 0;
        pair<TreeNode*, int> p = make_pair(root,1);
        q.push(p);
        while (!q.empty() && (p.first != NULL)) {
            ++line;
            ++oldline;
            auto v = new vector<int>;
            while (!q.empty() && (q.front().second == oldline)) {
                p = q.front();
                v->push_back(p.first->val);
                if (p.first->left != NULL)
                    q.push(make_pair(p.first->left, line));
                if (p.first->right != NULL)
                    q.push(make_pair(p.first->right, line));
                q.pop();
            }
            vec.push_back(*v);
            delete v;
        }
        return vec;
    }
};
```