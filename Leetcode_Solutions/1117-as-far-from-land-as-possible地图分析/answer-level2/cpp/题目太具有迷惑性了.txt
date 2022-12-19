### 解题思路
这道题目的难点在于看懂题目。如果看懂的话，就很简单。

这道题目其实我之前也没看懂。后面看了评论区，就懂了。

这道题目其实就是对所有的陆地出发，找最远的就可以了。

那么就是[994.腐烂的橘子](https://leetcode-cn.com/problems/rotting-oranges/)。

基本上改一些参数，就可以实现本题了。
### 代码

```cpp
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int fresh = 0;
        int min_count = 0;
        //对所有数据进行遍历，将腐烂的放入到队列之中，记录新鲜桔子的个数
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 1) q.push({i,j});
                else if(grid[i][j] == 0) fresh++;
            }
        }
        if(fresh == 0) return -1;
        int dir_x[4] = {0,0,-1,1};
        int dir_y[4] = {-1,1,0,0};
        while(!q.empty()){
            int size = q.size();
            bool is_rotton = false;
            //对当前队列的所有数据进行操作
            for(int i=0;i<size;i++){
                pair<int,int> current = q.front();
                q.pop();
                //判定四个方位是否有满足条件的橘子
                for(int j=0;j<4;j++){
                    int now_x = current.first  + dir_x[j];
                    int now_y = current.second + dir_y[j];
                    if(now_x >= 0 && now_x < grid.size() 
                    && now_y >= 0 && now_y < grid[0].size() 
                    && grid[now_x][now_y] == 0){
                            fresh--;
                            q.push({now_x,now_y});
                            grid[now_x][now_y] = 1;
                            is_rotton = true;
                        }
                }
            }
            //队列遍历完后，判定是否能否腐烂橘子
            if(is_rotton) min_count++;
        }
        //这里如果还有新鲜的，则说明并没有全部腐烂
        if(fresh) return -1;
        else return min_count;
    }
};
```