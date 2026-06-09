### 解题思路
没啥值得详细阐述的。大致思路如下：
遍历grid中的每一个节点，设置count变量计数岛屿数量；
如果遍历到值为1的节点，则count++并从该节点开始对值为1的节点进行BFS，经过的节点值改为2（避免重复），BFS结束后继续grid的遍历。

### 代码

```cpp
class Solution {
public:
    void explore(vector<vector<char>>& grid, int row, int col){  //保证grid[row][col]=1
        grid[row][col] = '2';
        //四向探索
        if(row > 0 && grid[row - 1][col] == '1'){
            explore(grid, row-1, col);
        }
        if(row < grid.size()-1 && grid[row + 1][col] == '1'){
            explore(grid, row+1, col);
        }
        if(col > 0 && grid[row][col-1] == '1'){
            explore(grid, row, col-1);
        }
        if(col < grid[0].size()-1 && grid[row][col+1] == '1'){
            explore(grid, row, col+1);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;
        int count = 0;
        for(int row = 0; row < grid.size(); row++){
            for(int col = 0; col < grid[0].size(); col++){
                if(grid[row][col] == '1'){
                    count ++;
                    explore(grid, row, col);
                }
            }
        }
        return count;
    }
};
```