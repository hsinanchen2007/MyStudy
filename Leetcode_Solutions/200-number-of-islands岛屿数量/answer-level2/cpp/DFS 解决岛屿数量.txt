### 解题思路
使用DFS，不断往深处迭代，在到每个岛屿的第一个‘1’的时候计数加一，而后不断扩展的过程中碰到‘1’就将其变为‘0’，碰到‘0’则停止迭代（终止迭代的条件）。
注意：分清楚循环的内外层与行列对应以及边界条件的对应。vector两下标按顺序对应行，列循环最好。

### 代码

```cpp
class Solution {
public:
    int m;
    int n;
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty())return 0;
        int result = 0;
        m = grid.size();//row
        n = grid[0].size();//colum
        for (int i = 0 ; i < m ; i++){
            for (int j = 0 ; j < n ; j++){
                if(grid[i][j] == '1'){
                    result+=1;
                    visit(grid, i, j);
                }
            }
        }
        return result;
    }
    void visit(vector<vector<char>>& grid,int x, int y){
        if( x>m-1 || x<0 || y>n-1 || y<0 || grid[x][y]=='0'){
            return;
        }
        grid[x][y]='0';
        visit(grid,x+1,y);
        visit(grid,x-1,y);
        visit(grid,x,y+1);
        visit(grid,x,y-1);
    }
    
};


```