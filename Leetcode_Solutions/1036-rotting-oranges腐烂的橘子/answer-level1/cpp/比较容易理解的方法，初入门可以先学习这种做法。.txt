### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        using p = pair<int, int>;
        vector<vector<int>> moves{{0,1},{0,-1},{-1,0},{1,0}};
        queue<p> que;
        int cnt = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    que.push(p(i, j));
                    grid[i][j]=0;
                }else if(grid[i][j]==1){
                    cnt++;
                }
            }
        }
        int step = 0;
        while(!que.empty()&&cnt>0){//注意判断条件不止有队列为空时退出，还要求不存在拓展点时也要退出。
            int sz = que.size();
            while(sz--){
                p cur = que.front();
                que.pop();
                for(int i=0;i<4;i++){
                    int x=cur.first+moves[i][0];
                    int y=cur.second+moves[i][1];
                    if(x>=0&&x<grid.size()&&y>=0&&y<grid[0].size()&&grid[x][y]==1){
                        que.push(p(x, y));
                        grid[x][y]=0;
                        cnt--;
                    }
                }
            }
            step++;
        }
        return cnt?-1:step;
    }
};
```