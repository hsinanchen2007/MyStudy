BFS

代码：
```
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int> > ans;
        vector<TreeNode*> bfs;
        if (root != NULL)
            bfs.push_back(root);
        vector<int> temp;
        while (!bfs.empty()) {
            int len = bfs.size();
            for (int i = 0; i < len; i++) {
                temp.push_back(bfs[i]->val);
                if (bfs[i]->left != NULL)
                    bfs.push_back(bfs[i]->left);
                if (bfs[i]->right != NULL)
                    bfs.push_back(bfs[i]->right);
            }
            bfs.erase(bfs.begin(), bfs.begin() + len);
            ans.insert(ans.begin(),temp);
            temp.clear();
        }
        return ans;
    }
};
```
