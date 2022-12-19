### 解题思路

1. BFS，需要在哈希表里同时保存x, y 坐标；
2. x为坐标，先按x排序第一维；
3. y为层序，然后按y排序第二维；
4. 对于相同的y，按照数字大小排序。

### 代码

```cpp
class Solution {
private:
    map<int, vector<pair<int, int>>> dict;
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        if(!root)
            return res;
        queue<pair<TreeNode *, int>> Q;
        Q.emplace(root, 0);
        dict[0].push_back(make_pair(0, root->val));
        
        int level = 0;
        while(!Q.empty()) {
            int n = Q.size();
            level++;
            for(int i=0; i<n; i++) {
                auto cur = Q.front();
                Q.pop();
                auto node = cur.first;
                int idx = cur.second;
                if(node->left) {
                    Q.emplace(node->left, idx - 1);
                    dict[idx-1].push_back(make_pair(level, node->left->val));
                }
                if(node->right) {
                    Q.emplace(node->right, idx + 1);
                    dict[idx+1].push_back(make_pair(level, node->right->val));
                }
            }
        }
        
        for(auto& p: dict) {
            sort(p.second.begin(), p.second.end(), [](const pair<int, int>& lhs, const pair<int, int>& rhs) {
                if(lhs.first != rhs.first)
                    return lhs.first < rhs.first;
                else
                    return lhs.second < rhs.second;
            });
            vector<int> tmp;
            for(auto& l: p.second)
                tmp.push_back(l.second);
            res.push_back(tmp);
        }
        return res;
    }
};
```