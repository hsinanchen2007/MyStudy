### 解题思路
依次找到为1的点进行BFS
直至没有1的点
- O(N^2)思考可以同时对多个1的点展开BFS
- 需要思考何时剪枝不继续BFS

### 代码

```cpp
class Solution {
private:
    queue<int> myque_col;
    queue<int> myque_row;
    int step;
public:
    int numIslands(vector<vector<char>>& grid) {
        // 对第一个搜索到的岛屿进行BFS根据距离将其所有相邻的岛屿置为step
        // 队列为空时再寻找下一个岛屿
        // 需要map存储已经找过的岛屿
        int rst = 0;
        if(grid.size()>0){
            bool cirle_end;
            while(true){
                cirle_end = false;
                for(int i=0; i< grid.size(); ++i){
                    for(int j=0; j<grid[i].size(); ++j){
                        if(grid[i][j] == '1'){
                            myque_col.push(i);
                            myque_row.push(j);
                            grid[i][j] -= 2; // 改为-1
                            cirle_end = true;
                            ++rst;
                            break;
                        }
                    }
                    if(cirle_end) break;
                }//找到第一个为1的点
                if(!cirle_end) break;
                step = 1;
                int tag;
                while(!myque_col.empty()){
                    ++step;
                    tag = myque_col.size();
                    for(int i=0; i<tag; ++i){
                        if(myque_col.front() > 0) getnextIslands(grid, myque_col.front() - 1, myque_row.front()); //上
                        if(myque_col.front() < grid.size()-1)    getnextIslands(grid, myque_col.front()+1, myque_row.front()); // 下
                        if(myque_row.front() < grid[0].size()-1) getnextIslands(grid, myque_col.front(), myque_row.front()+1); // 右
                        if(myque_row.front() > 0) getnextIslands(grid, myque_col.front(), myque_row.front() - 1); //左
                        myque_col.pop();
                        myque_row.pop();
                    }//像四个方向查找
                }
            }// 退出条件是当前列表里没有没被访问过的点O(n^3)
        }
        return rst;
    }
    void getnextIslands(vector<vector<char>>& grid, int col_cur, int row_cur){
        if(grid[col_cur][row_cur] == '1') {
            grid[col_cur][row_cur] += step;
            myque_col.push(col_cur);
            myque_row.push(row_cur);
        }
    }
    // O(N^2) 将所有为1的岛屿并入
    // 最后搜寻所有为0的结点
};
```