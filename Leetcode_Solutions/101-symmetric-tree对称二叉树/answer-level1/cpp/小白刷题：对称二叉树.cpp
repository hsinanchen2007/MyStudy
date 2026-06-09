BFS，遍历每一层并判断是否对称

代码：
```
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        vector<TreeNode*> bfs;
        bfs.push_back(root);
        while (!bfs.empty()) {
            int len = bfs.size();
            for (int i = 0; i < len; i++) {
                if (bfs[i] != NULL) {
                    bfs.push_back(bfs[i]->left);
                    bfs.push_back(bfs[i]->right);
                }
            }
            bfs.erase(bfs.begin(), bfs.begin() + len);
            for (int i = 0; i < bfs.size() / 2; i++) {
                if (bfs[i] == NULL && bfs[bfs.size() - 1 - i] == NULL)
                    continue;
                else if(bfs[i] != NULL && bfs[bfs.size() - 1 - i] != NULL && bfs[i]->val == bfs[bfs.size() - 1 - i]->val)
                    continue;
                return false;
            }
        }
        return true;
    }
};
```
