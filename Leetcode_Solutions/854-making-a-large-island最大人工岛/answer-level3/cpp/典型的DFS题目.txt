### 1. 暴力解法
简单的尝试将每一个0染成1，然后对该染色点DFS，得到最大连通集的大小，即连通后的岛屿面积，最后保留最大值。
方法和代码都简单易懂，只不过运行时间要需要1300+ms，还好是C++，最终并没有超时，可是这个效率也太低了。

### 代码

```cpp
class Solution {
    int area;
    vector<vector<bool>> visited;
    void dfs(int i, int j, vector<vector<int>>& grid)
    {
        if(!visited[i][j])
        {
            visited[i][j] = true;
            if(grid[i][j])
            {
                area++;
                if(i > 0) dfs(i - 1, j, grid);
                if(i + 1 < grid.size()) dfs(i + 1, j, grid);
                if(j > 0) dfs(i, j - 1, grid);
                if(j + 1 < grid.size()) dfs(i, j + 1, grid);
            }
        }
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid.size(); j++)
            {
                if(!grid[i][j])
                {
                    grid[i][j] = 1;
                    area = 0;
                    visited.assign(grid.size(), vector<bool>(grid.size(), false));
                    dfs(i, j, grid);
                    maxArea = max(area, maxArea);
                    grid[i][j] = 0;
                }
            }
        }
        if(0 == maxArea) maxArea = grid.size() * grid.size();
        return maxArea;
    }
};
```

### 2. 一遍全图DFS
仔细思考一下，前面的暴力解法有大量的重复计算，其实只需要一次全图DFS就够了。也就是说，计算出每个点所在的岛屿的大小，最后遍历一遍每个0，考察期相邻点的岛屿大小，即可在常数时间内计算出连通后的总大小。
这里面存在的问题就是一个判重问题，其实并不难理解，也就是说一个点的上、下、左、右四个相邻点中，属于相同岛屿的不能重复计算。
代码中采取的方案是在DFS过程中给每个点标记上岛屿的编号，并用一个数组储存对应编号岛屿的面积。这样就可以根据岛屿的编号来判重避免重复计算了。
最终运行时间为16ms，可以看出运行效率得到了极大的提升。
代码里面判重部分写的稍有些粗糙，因为还需要顾及边界问题。

### 代码

```cpp
class Solution {
    vector<int> areaList;
    vector<vector<bool>> visited;
    int offset[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    #define IN_RANGE(x) (((x) >= 0) && ((x) < grid.size()))

    void dfs(int i, int j, int aInd, vector<vector<int>>& grid)
    {
        if(!visited[i][j])
        {
            visited[i][j] = true;
            if(grid[i][j])
            {
                areaList[aInd]++;
                grid[i][j] = aInd;

                int x, y;
                for(int k = 0; k < 4; k++)
                {
                    x = i + offset[k][0];
                    y = j + offset[k][1];
                    if(IN_RANGE(x) && IN_RANGE(y)) dfs(x, y, aInd, grid);
                }
            }
        }
    }

public:
    int largestIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        int area;
        int areaInd = 1;
        visited.assign(grid.size(), vector<bool>(grid.size(), false));
        areaList.assign({0});
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid.size(); j++)
            {
                if((grid[i][j]) && (!visited[i][j]))
                {
                    areaList.push_back(0);
                    dfs(i, j, areaInd++, grid);
                }
            }
        }

        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid.size(); j++)
            {
                if(!grid[i][j])
                {
                    area = 1;
                    int x, y;
                    for(int k = 0; k < 4; k++)
                    {
                        x = i + offset[k][0];
                        y = j + offset[k][1];
                        if(IN_RANGE(x) && IN_RANGE(y))
                        {
                            bool duplicate = false;
                            int xx, yy;
                            for(int kk = 0; kk < k; kk++)
                            {
                                xx = i + offset[kk][0];
                                yy = j + offset[kk][1];
                                if(IN_RANGE(xx) && IN_RANGE(yy) && (grid[x][y] == grid[xx][yy]))
                                {
                                    duplicate = true;
                                    break;
                                }
                            }
                            if(!duplicate) area += areaList[grid[x][y]];
                        }
                    }
                    maxArea = max(area, maxArea);
                }
            }
        }
        
        if(0 == maxArea) maxArea = grid.size() * grid.size();
        return maxArea;
    }
};
```