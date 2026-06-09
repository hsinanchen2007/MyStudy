

### 代码

```cpp
class Solution {
private:
    vector<vector<int>>record={{0,-1},{0,1},{1,0},{-1,0}};
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int,int>>q;
        for(int i = 0;i < n;i++)
            for(int j = 0;j < n;j++){
                if(grid[i][j] == 1)
                    q.push({i,j});
            }
            if(q.size() == 0 || q.size() == n * n)
                return -1;
            int ans=-1;
            while(!q.empty()){
                ans++;
                int count = q.size();
                while(count--){
                    pair<int,int>tmp = q.front();
                    q.pop();
                    for(auto&d:record){
                        int x = tmp.first + d[0];
                        int y = tmp.second + d[1];
                        if(x<0 || x>=n || y<0 || y>=n ||grid[x][y]==1)
                            continue;
                        grid[x][y]=1;
                        q.push({x,y});
                    }
                }
            }
            return ans;

    }
};
```