### 思路
维护一个队列和一个集合，队列中存放当前时间坏的橘子，集合中存放当前所有好的橘子，当好的橘子被某个坏橘子腐坏时，需从坏橘子队列中弹出该坏橘子，然后从好橘子集合中移除该好橘子，并将其新加入坏橘子队列中。不断循环，直到坏橘子队列为空。最后如果后好的橘子集合大小大于0，证明无法全部腐坏，返回-1.

### 代码

```cpp
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int res = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<pair<int,int>> dirs;
        dirs.push_back(make_pair(-1,0));
        dirs.push_back(make_pair(1,0));
        dirs.push_back(make_pair(0,-1));
        dirs.push_back(make_pair(0,1));
        queue<pair<int,int>> rot;
        multiset<pair<int,int>> good;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2) rot.push(make_pair(i,j));
                if(grid[i][j] == 1) good.insert(make_pair(i,j));
            }
        }
        while(!rot.empty()){
            int size = rot.size();
            int flag = 0; 
            for(int i = 0; i < size; i++){
                auto [x,y] = rot.front(); rot.pop();
                for(auto couple : dirs){
                    auto tmp = make_pair(x+couple.first,y+couple.second);
                    if(good.find(tmp) != good.end()){ //找到有与腐烂橘子相邻的好橘子
                        good.erase(tmp);    //好橘子被传染，从好橘子集合移除
                        rot.push(tmp);      //加入坏橘子队列
                        flag = 1;
                    }
                }
            }
            if(flag) res+=1;
        }
        if(good.size() > 0) return -1;
        return res;
    }
};