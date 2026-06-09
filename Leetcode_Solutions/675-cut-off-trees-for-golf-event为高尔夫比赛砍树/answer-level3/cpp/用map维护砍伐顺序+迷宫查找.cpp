map可保证key有序，用于记录树木砍伐的顺序。
通过广度遍历查找当前点到下一棵树的最短路径。
```
class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        int m = forest.size();
        if(m==0) return 0;
        int n = forest[0].size();
        if(n==0) return 0;
        map<int, vector<int>> ma;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(forest[i][j]==0) continue;
                ma[forest[i][j]] = {i, j};
            }
        }
        int x = 0, y = 0, res = 0;
        for(auto it: ma) {
            int i = it.second[0], j = it.second[1];
            int ans = find(forest, x, y, i, j);
            // cout<<i<<j<<ans<<endl;
            if(ans==-1) return -1;
            res += ans;
            forest[i][j] = 1;
            x = i, y = j;
        }
        return res;
    }
    int find(vector<vector<int>>& forest, int x, int y, int i, int j) {
        int m = forest.size(), n = forest[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        q.push({x, y});
        int level = 0;
        while(!q.empty()) {
            int t = q.size();
            while(t--) {
                auto p = q.front();
                q.pop();
                if(p.first==i && p.second==j) return level;
                if(vis[p.first][p.second] || forest[p.first][p.second]==0) continue;
                vis[p.first][p.second] = true;
                if(p.first>0) q.push({p.first-1, p.second});
                if(p.first<m-1) q.push({p.first+1, p.second});
                if(p.second>0) q.push({p.first, p.second-1});
                if(p.second<n-1) q.push({p.first, p.second+1});
            }
            level++;
        }
        return -1;
    }
};
```