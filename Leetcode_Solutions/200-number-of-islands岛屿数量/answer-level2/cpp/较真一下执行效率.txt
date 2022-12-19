首先解题接替思路在高分答案已经有很多了，也不是个人擅长。总之就是深度优先遍历算法，每次找到一个有效的点就把整个岛屿探索一遍。

本文主要想说的是，执行速度和leetcode后台服务器应该是有关系的，解答中除了最下面的3次是个人尝试不同的实现后提交的答案外，其他均是高分答案的题解，但是时间都比第一次执行时间长，包括一次回答是8ms的答案，现在执行时间也是16ms。

![image.png](https://pic.leetcode-cn.com/a02adc2f5548d4cb571b01d6044d19d302734f08cd97958dab119460977accd7-image.png)

放代码：

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int islandCount=0;

        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='1' )
                {
                    islandCount++;
                    searchIsland(grid,i,j);
                }
            }
        }

        return islandCount;
    }

    void searchIsland(vector<vector<char>>& grid,int i,int j )
    {
        if(grid[i][j]=='1')
        {
            grid[i][j]=2;
        }
        else
        {
            return;
        }
        
        if(i>0)
        {
            searchIsland(grid,i-1,j);
        }

        if(j>0)
        {
            searchIsland(grid,i,j-1);
        }

        if(i<grid.size()-1)
        {
            searchIsland(grid,i+1,j);
        }

        if(j<grid[0].size()-1)
        {
            searchIsland(grid,i,j+1);
        }
    }
};