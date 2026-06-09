### 解题思路
此处撰写解题思路
看到这个题的时候想到了机器人路径的那道动态规划题，这道题与之不同的是，没有固定的重点，并且起点不同，这就意味着任何一个位置grid[i][j]都有可能是起点，前提是这个位置的值为1，作为起点之后，这个位置就应该标记为已经使用过，然后在它的上下左右去寻找新的领土，方法和前面描述的是一样的。
标记在这里是十分重要的，可以省去多余的操作，比如以题目中的第一个实例为例，以grid[0][7]为起始点检索到的岛屿面积为4，以grid[1][7]为起点检索到的岛屿面积也是4，而且其实是同一座岛屿，所以我们可以利用flag只以grid[0][7]为起点检索一次。

### 代码

```cpp
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        int row=grid.size(), col=grid[0].size();
        int maxArea=0;
        vector<vector<bool>> flag(row, vector<bool>(col, false));
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                maxArea = max(maxArea, find(i, j, row, col, flag, grid));
            }
        }
        return maxArea;
    }
    int find(int i, int j, int row, int col, vector<vector<bool>> &flag, vector<vector<int>>& grid){
        if(i<0 || j<0 || i>=row || j>=col) return 0;
        if(grid[i][j]==1 && flag[i][j]==false){
            flag[i][j]=true;
            return 1+find(i-1, j, row, col, flag, grid)+find(i+1, j, row, col, flag, grid)
            +find(i, j-1, row, col, flag, grid)+find(i, j+1, row, col, flag, grid);
        }
        else return 0;
    }
};
```