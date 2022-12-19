### 解题思路
  题目的意思其实就是哪个海洋区域到所有陆地区域的距离最远。不用管那个什么距离，那个距离其实就是你从四个方向走一步，那个距离值就增1.
  因此，就只需要从每个陆地开始走起，走到不能走为止。这个值就是最大的。

### 代码

```cpp
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n == 1)return -1;
        queue<pair<int,int>> q;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j]){
                    q.push(make_pair(i,j));
                }
            }
        }
        if(q.empty() || q.size() == n * n)return -1;
        int d[4][2] = {0,1,0,-1,1,0,-1,0};
        int s = 0;
        while(!q.empty()){
            int l = q.size();
            s++;
            //每个陆地都走一步，走到不能走为止。
            while(l--){
                pair<int,int> t = q.front();
                q.pop();
                for(int i = 0 ; i < 4 ; i++){
                    int x = t.first + d[i][0];
                    int y = t.second + d[i][1];
                    if(x < 0 || x >= n || y < 0 || y >= n || grid[x][y])continue;
                    grid[x][y] = 1;
                    q.push(make_pair(x,y));
                }
            }
        }
        return s - 1;
    }
};
```