### 解题思路
见代码
### 代码

```cpp
class Solution {
public:
    //类似求连通图，优先DFS，一次DFS正好遍历一个连通图
    int X[8] = {0, 0, 1, -1, 1, -1, 1, -1};
    int Y[8] = {1, -1, 0, 0, 1, -1, -1, 1};
    void dfs(vector<vector<int>>& land, vector<vector<bool>>& vis, int x, int y, int& ans){
        //操作
        vis[x][y] = true;
        ans++;
        //选择
        int a,b;
        for(int i = 0; i < 8; i++) {
            a = x + X[i];
            b = y + Y[i];
            if(a < 0 || a >= land.size() || b < 0 || b >= land[0].size()) continue;  //判断越界
            if(vis[a][b] == false && land[a][b] == 0) {
                dfs(land, vis, a, b, ans);
            }
        }
    }
    vector<int> pondSizes(vector<vector<int>>& land) {
        vector<vector<bool>> vis(land.size(), vector<bool>(land[0].size(), false));
        vector<int> ans;
        for(int i = 0; i < land.size(); i++) {
            for(int j = 0; j < land[0].size(); j++) {
                if(vis[i][j] == false && land[i][j] == 0) {
                    int temp = 0;
                    dfs(land, vis, i, j, temp);
                    ans.push_back(temp);
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
```