### 解题思路
采用spfa，把更新的节点放入队列当中。

### 代码

```cpp
class Solution {
public:
    int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    std::queue<int> que;
 
    int maxval = 0;
    void spfa(vector<vector<int>>& grid, int size){
          while(!que.empty()){
              int qsize = que.size();
              for(int index=0; index<qsize;index++){
                int tmp = que.front();
                que.pop();
                int i = tmp/100;
                int j= tmp%100;
                for(int k=0; k<4; k++){
                    int nexti = i + dir[k][0];
                    int nextj = j + dir[k][1];
                    if(nexti>=0 && nextj>=0 && nexti<size && nextj<size){
                        if(grid[nexti][nextj] == 0){
                            grid[nexti][nextj] = 1;
                            que.push(nexti*100 + nextj);
                        }
                    }
                }
            }
            maxval++;
          }
    }
    int maxDistance(vector<vector<int>>& grid) {
        if(grid.empty()){
            return -1;
        }
        int n = grid.size();

        for(int i=0; i<n;i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){
                    que.push(100*i + j);
                }
            }
        }
        if(que.size() == n*n || que.size()==0){
            return -1;
        }
        spfa(grid, n);
        return maxval-1;
    }
};
```