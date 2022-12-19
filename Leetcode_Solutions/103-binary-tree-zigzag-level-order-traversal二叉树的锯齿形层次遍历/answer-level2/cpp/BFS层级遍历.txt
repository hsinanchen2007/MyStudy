### 解题思路

BFS层级遍历

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root)
            return res;
        queue<TreeNode *> Q;
        Q.push(root);
        
        int L = 0;
        while(!Q.empty()) {
            int n = Q.size();
            vector<int> level;
            for(int i=0; i<n; i++) {
                auto cur = Q.front();
                Q.pop();
                level.push_back(cur->val);
                if(cur->left)
                    Q.push(cur->left);
                if(cur->right)
                    Q.push(cur->right);
            }
            if(L % 2) {
                reverse(level.begin(), level.end());
            }
            res.push_back(level);
            L++;
        }
        return res;
    }
};
```

执行用时 :4 ms, 在所有 C++ 提交中击败了89.51% 的用户     (时间复杂度O(N）)
内存消耗 :13.8 MB, 在所有 C++ 提交中击败了13.25%的用户  （空间复杂度O(N)）