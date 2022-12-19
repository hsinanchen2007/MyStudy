### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        queue<vector<int>> one;
        int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        map<pair<int,int>, bool> visited;
        for(int i = 0;i < grid.size();i++){
            for(int j = 0;j < grid[0].size();j++){
                if(grid[i][j] == 1){
                    vector<int> node = {i,j};
                    one.push(node);
                }
            }
        }
        int maxsize = 0;
        while(!one.empty()){
            vector<int> dirt(one.front());
            one.pop();
            pair<int,int> cor = make_pair(dirt[0],dirt[1]);
            if(visited[cor]) continue;
            else visited[cor] = true;
            int size = 1;
            queue<vector<int>> lands;
            for(int i = 0;i < 4;i++){
                int nexti = dirt[0] + dir[i][0];
                int nextj = dirt[1] + dir[i][1];
                if(nexti >= 0 && nexti < grid.size() && nextj >= 0 && nextj < grid[0].size() && grid[nexti][nextj] && !visited[make_pair(nexti, nextj)]){
                    size++;
                    visited[make_pair(nexti,nextj)] = true;
                    vector<int> node = {nexti,nextj};
                    lands.push(node);
                }
            }
            while(!lands.empty()){
                vector<int> newland(lands.front());
                lands.pop();
                pair<int,int> cordinate = make_pair(newland[0],newland[1]);
                for(int i = 0;i < 4;i++){
                    int nexti_ = newland[0] + dir[i][0];
                    int nextj_ = newland[1] + dir[i][1];
                    if(nexti_ >= 0 && nexti_ < grid.size() && nextj_ >= 0 && nextj_ < grid[0].size() && grid[nexti_][nextj_] && !visited[make_pair(nexti_, nextj_)]){
                        size++;
                        visited[make_pair(nexti_,nextj_)] = true;
                        vector<int> node = {nexti_,nextj_};
                        lands.push(node);
                    }
                }
            }
            maxsize = max(maxsize, size);
        }
        return maxsize;
    }
};
```