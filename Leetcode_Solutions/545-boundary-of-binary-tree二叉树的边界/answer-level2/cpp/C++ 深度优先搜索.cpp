### 解题思路
深度优先搜索
1，利用dir标示父节点的方向
2，对于左方向是先序遍历，对于右方向是后序遍历，对于无方向的则只遍历到叶节点即可

### 代码

```cpp
class Solution {
public:
    void dfs(TreeNode* root, int dir, vector<int>& res) {
        if (root == NULL) return;
        // 无方向，寻找叶节点
        if (dir == 0) {
            if (root->left == NULL && root->right == NULL) {
                res.push_back(root->val);
            } else {
                dfs(root->left, 0, res);
                dfs(root->right, 0, res);
            }
            return;
        }
        // 左方向，先序遍历
        if (dir == -1) {
            res.push_back(root->val);
            if (root->left) {
                dfs(root->left, dir, res);
                dfs(root->right, 0, res);
            } else {
                dfs(root->right, dir, res);
            }
        } else { // 右方向，后序遍历
            if (root->right) {
                dfs(root->left, 0, res);
                dfs(root->right, dir, res);
            } else {
                dfs(root->left, dir, res);
            }
            res.push_back(root->val);
        }
    }
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if (root == NULL) return {};
        vector<int> res{root->val};
        dfs(root->left, -1, res);
        dfs(root->right, 1, res);
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/d088c65fd889a38eea22f307fadbf203833fdadf9c7f0113e50227e58d32a78f-image.png)
