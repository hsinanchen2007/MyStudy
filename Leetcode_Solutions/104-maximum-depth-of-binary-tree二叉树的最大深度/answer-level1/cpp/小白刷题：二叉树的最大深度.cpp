BFS，统计层数

代码：
```
class Solution {
public:
    int maxDepth(TreeNode* root) {
        vector<TreeNode*> bfs;
        int ans = 0;
        if (root != NULL)
        bfs.push_back(root);
        while (!bfs.empty()) {
            ans++;
            int len = bfs.size();
            for (int i = 0; i < len; i++) {
                if (bfs[i]->left != NULL)
                    bfs.push_back(bfs[i]->left);
                if (bfs[i]->right != NULL)
                    bfs.push_back(bfs[i]->right);
            }
            bfs.erase(bfs.begin(), bfs.begin() + len);
        }
        return ans;
    }
};
```
