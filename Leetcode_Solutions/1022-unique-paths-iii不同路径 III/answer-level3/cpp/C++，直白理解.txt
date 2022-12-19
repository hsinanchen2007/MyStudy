### 解题思路
C++提交太少了，我来做个贡献。
首先找到开始点，结束点的位置。
从开始点开始，自动向四周移动监测。走过的位置变成障碍-1.
步数达到最大步数，且到达结束点，为一次成功。

### 代码

```cpp
class Solution {
private:
    int lenRow;
    int lenCol;
    int passneed;
    int startx, starty;
    int endx, endy;
    int rlt;
    
public:
    //自动像四周移动监测，递交地图，坐标，和已经走的步数
    void dfs(vector<vector<int>> grid, int i, int j, int pass)
    {
        if (i<0 || i>=lenRow || j<0 || j>=lenCol || grid[i][j] == -1)
            return;
        cout << "now at:(" << i << ", " << j << ") pass:" << pass << endl;
        if (i == endx && j == endy && pass == passneed)
        {
            cout << "Victoria"<<endl;
            rlt++;
            return;
        }
        
        grid[i][j] = -1;
        
        dfs(grid, i+1, j, pass+1);
        dfs(grid, i-1, j, pass+1);
        dfs(grid, i, j+1, pass+1);
        dfs(grid, i, j-1, pass+1);
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        lenRow = grid.size();
        lenCol = grid[0].size();
        passneed = lenRow * lenCol;
        rlt = 0;
        
        //记录开始点和结束点的位置，还有最多需要的步数
        for (int i=0; i<lenRow; i++)
        {
            for (int j=0; j<lenCol; j++)
            {
                if (grid[i][j] == 1)
                {
                    startx = i;
                    starty = j;
                }
                else if (grid[i][j] == 2)
                {
                    endx = i;
                    endy = j;
                }
                else if (grid[i][j] == -1)
                {
                    passneed--;
                }
            }
        }
        cout << "Pass need:" << passneed << endl;
        cout << "Start at:(" << startx << ", " << starty << ")" << endl;
        cout << "End at:(" << endx << ", " << endy << ")" << endl;
        dfs(grid, startx, starty, 1);
        return rlt;
    }
};
```