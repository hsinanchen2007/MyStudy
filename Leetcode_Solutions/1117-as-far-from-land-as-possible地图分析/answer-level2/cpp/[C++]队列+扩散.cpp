### 解题思路
思路与[这里](https://leetcode-cn.com/problems/as-far-from-land-as-possible/solution/lu-di-bu-duan-chang-da-zhi-dao-fu-gai-zheng-ge-di-/)完全相同。
[烂橘子题目](https://leetcode-cn.com/problems/rotting-oranges/solution/fu-lan-de-ju-zi-by-leetcode-solution/)的变式。

### 代码

```cpp
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        if(grid.size() == 0 || grid[0].size() ==0)return -1;
        queue<pair<int, int>> res;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size();j++){
                if(grid[i][j] == 1){
                    res.push(make_pair(i, j));
                }
            }
        }
        int rest = grid.size() * grid[0].size() - res.size();
        if(res.size() == 0 || rest == 0)return -1;
        int col[] = {-1, 0, 1, 0}, rol[] = {0, -1, 0, 1};
        int dist = 0;
        while(rest > 0){
            for(int i = res.size(); i > 0; i--){
                pair<int, int> temp = res.front();
                res.pop();
                for(int j = 0; j < 4; j++){
                    int dx = temp.first + col[j], dy = temp.second + rol[j];
                    if( dx < 0 ||dx >= grid.size() || dy < 0 || dy >= grid[0].size())continue;
                    if(grid[dx][dy] == 0){
                        rest--;
                        grid[dx][dy] = grid[temp.first][temp.second] + 1;
                        dist = max(grid[dx][dy], dist);
                        res.push(make_pair(dx, dy));
                    }
                    if(rest < 1)break;
                }
            }
        }
        return dist - 1;

    }
};
```