### 解题思路
此处撰写解题思路
这道题有两种解法。
解法一: dfs。
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
    vector<vector<int>> result;

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        bfs(root, 0);
        
        // 因为题目需要自底向上
        reverse(result.begin(), result.end());
        return result;

    }

    void bfs(TreeNode *root, int depth) {
        if (!root) return;
        TreeNode *curr = root;
        if (depth >= result.size()) {
            vector<int> item;
            result.push_back(item);
        }
        result[depth].push_back(root->val);
        if (root->left) bfs(root->left,depth+1);
        if (root->right) bfs(root->right, depth+1);

    }
};
```

解法二：bfs，使用队列。

```
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
    vector<vector<int>> result;

    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        if (!root) return result;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> level_res;
            int qsize = q.size();
            for (int i = 0; i < qsize; i++) {
                TreeNode *node = q.front();
                q.pop();
                level_res.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            result.push_back(level_res);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
```
