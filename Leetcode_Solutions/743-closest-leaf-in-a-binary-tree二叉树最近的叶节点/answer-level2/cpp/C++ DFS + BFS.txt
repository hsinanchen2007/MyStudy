# 思路：
1，先深度优先搜索获取每一个点的父节点
2，后广度优先搜索获取结果

```C++ []
class Solution {
public:
    map<TreeNode*, TreeNode*> parents;
    void dfs(TreeNode* root, int k, TreeNode** src) {
        if (*src == NULL && root != NULL && root->val == k) {
            *src = root;
        }
        if (root->left) {
            parents[root->left] = root;
            dfs(root->left, k, src);
        }
        if (root->right) {
            parents[root->right] = root;
            dfs(root->right, k, src);
        }
    }
    int bfs(TreeNode* src) {
        queue<TreeNode*> q;
        q.push(src);
        set<TreeNode*> seen;
        seen.insert(src);
        int res = -1;
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            if (node->left == NULL && node->right == NULL) {
                res = node->val;
                break;
            }
            if (node->left && seen.count(node->left) == 0) {
                seen.insert(node->left);
                q.push(node->left);
            }
            if (node->right && seen.count(node->right) == 0) {
                seen.insert(node->right);
                q.push(node->right);
            }
            if (parents.count(node) && seen.count(parents[node]) == 0) {
                seen.insert(parents[node]);
                q.push(parents[node]);
            }
        }
        return res;
    }
    int findClosestLeaf(TreeNode* root, int k) {
        TreeNode* src = NULL;
        dfs(root, k, &src);
        return bfs(src);
    }
};
```
![image.png](https://pic.leetcode-cn.com/f41736dac3c456fe264828f5241bdaf3be0034cdd0684d84a4be6d0f5be84dff-image.png)
