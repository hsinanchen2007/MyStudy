### 解题思路
1.先找出所有的0
2.遍历每个0，计算与建筑的距离
3.取距离和最小值

### 代码

```cpp
class Solution {
public:
    int bfs(const vector<vector<int>>& grid,int x, int y,int building){
        vector<int> xdirect = {0,-1,0,1};
        vector<int> ydirect = {1,0,-1,0};
        vector<vector<int>> flag(grid.size(),vector<int>(grid[0].size()));
        queue<pair<int,int>> q;
        q.push(make_pair(x,y));
        flag[x][y] = 1;

        int xlimit = grid.size();
        int ylimit = grid[0].size();
        int level = 0,sum=0,reachable = 0,curLevelNum = 0;
        while(!q.empty()){
            level++;
            curLevelNum = q.size();
            while(curLevelNum-- > 0){
                auto node = q.front();
                q.pop();
                for(int i = 0; i < 4; ++i){
                    int newx = node.first+xdirect[i];
                    int newy = node.second+ydirect[i];
                    if(newx >=0&&newx<xlimit&&newy>=0&&newy<ylimit&&!flag[newx][newy]&&grid[newx][newy]!=2){
                        if(grid[newx][newy]==1){
                            reachable++;
                            sum += level;
                        }else{
                            q.push(make_pair(newx,newy));
                        }
                        flag[newx][newy] = 1;
                    }
                }
            }
        }
        if(reachable < building){
            return -1;
        }else{
            return sum;
        }
    }

    int shortestDistance(vector<vector<int>>& grid) {
        if(grid.size() == 0) return -1;
        vector<pair<int,int>> blank;
        int building = 0;
        for(int i = 0; i < grid.size();++i){
            for(int j = 0; j < grid[0].size();++j){
                if(grid[i][j] == 0){
                    blank.push_back(make_pair(i,j));
                }else if(grid[i][j] == 1){
                    ++building;
                }
            }
        }

        int minSum = INT_MAX;
        for(auto t:blank){
            int sum = bfs(grid,t.first,t.second,building);
            if(sum >= 0)
                minSum = min(minSum,sum);
        }
        return minSum == INT_MAX?-1:minSum;
    }
};
```