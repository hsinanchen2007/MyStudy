### 解题思路
大家写的基本都差不多，唯一的细节：遍历数组为1的岛屿之后，最好不要置为0，而是置为非0非1的数字，找到正确答案之后还原数组，养成良好的编程习惯，尽量不要改变输入。

### 代码

```cpp
int dict1[]={0,0,1,-1},dict2[]={1,-1,0,0};

class Solution {
public:
int BFS(vector<vector<int>>& grid,int row,int column,int r,int c)
{
    if(r<0 || c<0 || r>=row || c>=column || grid[r][c] != 1) return 0;
    int ans=1;
    grid[r][c]=2;
    for(int i=0;i<4;i++)
        ans+=BFS(grid,row,column,r+dict1[i],c+dict2[i]);
    return ans;
}
int maxAreaOfIsland(vector<vector<int>>& grid) 
{
    int row=grid.size();
    if(row==0) return 0;
    int column=grid[0].size();

    int ans=0;
    for(int i=0;i<row;i++)
        for(int j=0;j<column;j++)
            if(grid[i][j]==1)  ans=max(ans,BFS(grid,row,column,i,j));   
    for(int i=0;i<row;i++)
        for(int j=0;j<column;j++)
            if(grid[i][j]==2) grid[i][j]=1;
    return ans;
}
};
```