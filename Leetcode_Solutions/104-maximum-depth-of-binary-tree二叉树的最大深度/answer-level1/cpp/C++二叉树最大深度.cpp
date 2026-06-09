### 解题思路
此处撰写解题思路
一样的思路，保持广度优先搜索时给个depth标志位即可

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
    int maxDepth(TreeNode* root) {
        int depth=0;
        queue<TreeNode*> q;
        if (!root) return 0;
        q.push(root);
        
        while (!q.empty()) {
            int n = q.size();
            vector<int> level;
            while (n) {
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                n--;
            }
            depth++;
        }
        return depth;
    }
};
```