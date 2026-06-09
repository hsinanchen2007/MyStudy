### 解题思路

BFS 设置一个栈进行迭代，比递归好理解一些。
思路仍然是遇见1入栈，将它周围的1变为0。
最后剩下的1就是岛屿的数量

### 代码

```cpp
class Solution {
public:
    bool is_valid(int row,int col,int new_x,int new_y){
        return new_x>=0 &&  new_x < row && new_y >=0 && new_y < col;
    }



    int numIslands(vector<vector<char>>& grid) {
        
        int row = grid.size();
        if(row==0) return 0;

        int col = grid[0].size();
        
        queue<pair<int,int>> bfs_queue;
        int res = 0;

        int dx[] = {0,1,-1,0};
        int dy[] = {1,0,0,-1};
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j] == '0') continue;


                bfs_queue.push({i,j});
                res++;
                //cout<<res<<endl;
                while(!bfs_queue.empty()){
                    auto cur_pos = bfs_queue.front();
                    bfs_queue.pop();
                    
                    for(int i=0;i<4;i++){
                        int new_x = cur_pos.first + dx[i];
                        int new_y = cur_pos.second + dy[i];
                        if(is_valid(row,col,new_x,new_y) && grid[new_x][new_y] == '1'){
                            bfs_queue.push({new_x,new_y});
                            grid[new_x][new_y] = '0';
                        }
                    }
                }
            }
        }

        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/e706b625ef61036daf08d1c11fef2d606feff777f96529e5abdf70c6476f860d-image.png)
