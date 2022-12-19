### 解题思路
1 声明布尔数组，表明行列中某个数字是否被使用了， 被用过视为 true，没用过为 false，比如row[3][2]为true代表第四行已经有了3这个元素。（我觉得是最重要的一步）

2 初始化布尔数组，表示已经有哪些空格被填充了。

3 尝试去填充数组，只要行，列， 还有 3*3 的方格内出现已经被使用过的数字，我们就不填充，否则尝试填充。

4 如果填充失败，回溯到上一步。

5 递归直到数独被填充完成。

### 代码

```cpp
class Solution {
public:
    bool row[9][9] = {0},col[9][9] = {0},cell[3][3][9] = {0};
    void solveSudoku(vector<vector<char>>& board) {
        for(int i = 0;i<9;i++)
        {
            for(int j = 0;j<9;j++)
            {
                char c = board[i][j];
                if(c!='.')
                {
                    int t = c - '1';
                    row[i][t] = col[j][t] = cell[i/3][j/3][t] = true;
                }
            }
        }

        dfs(board,0,0);
    }

    bool dfs(vector<vector<char>>& board,int x,int y)
    {
        if(y == 9) x++,y = 0;
        if(x == 9) return true;
        if(board[x][y]!='.') return dfs(board,x,y+1);

        for(int i = 0;i<9;i++)
        {
            if(!row[x][i] && !col[y][i] && !cell[x/3][y/3][i])
            {
                board[x][y] = i + '1';
                row[x][i] = col[y][i] = cell[x/3][y/3][i] = true;
                if(dfs(board,x,y+1)) return true;
                row[x][i] = col[y][i] = cell[x/3][y/3][i] = false;
                board[x][y] = '.';
            }
        }

        return false;
    }
};
```
代码参考了***的创办者，大伙有兴趣可以去b站搜索大雪菜，他是***的创办者他的视频讲的很详细。