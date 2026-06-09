### 解题思路
经典的DFS题目。注意题目中地图为15x15，金矿数目不超过25，因此直接遍历所有金矿点，进行dfs即可，速度并不会慢。

如果只遍历端点及拐角点，无法解决“日”字形金矿分布。

注意：解决dfs时，使用数组记录走过的路线，处理完成后将标志还原。

![image.png](https://pic.leetcode-cn.com/30246b6ac05d3d10c11a0f1a826575d799b62ef948970ffa9153bf8ed33334e1-image.png)


### 代码

```c
/*
 * @lc app=leetcode.cn id=1219 lang=c
 *
 * [1219] 黄金矿工
 */

// @lc code=start
#define MMAX(a, b)  ((a) > (b)? (a) : (b))

int max;

int tags[15][15] = {0};

void helper(int** grid, int row, int col, int y, int x, int cnt)
{
    bool proc = false;

    //处理上
    if(y > 0 && tags[y - 1][x] == 0 && grid[y - 1][x] > 0)
    {
        proc = true;

        tags[y - 1][x] = 1;
        helper(grid, row, col, y - 1, x, cnt + grid[y - 1][x]);
        tags[y - 1][x] = 0;
    }

    //处理下
    if(y < row - 1 && tags[y + 1][x] == 0 && grid[y + 1][x] > 0)
    {
        proc = true;
        
        tags[y + 1][x] = 1;
        helper(grid, row, col, y + 1, x, cnt + grid[y + 1][x]);
        tags[y + 1][x] = 0;
    }

    //处理左
    if(x > 0 && tags[y][x - 1] == 0 && grid[y][x - 1] > 0)
    {
        proc = true;
        
        tags[y][x - 1] = 1;
        helper(grid, row, col, y, x - 1, cnt + grid[y][x - 1]);
        tags[y][x - 1] = 0;
    }

    //处理右
    if(x < col - 1 && tags[y][x + 1] == 0 && grid[y][x + 1] > 0)
    {
        proc = true;
        
        tags[y][x + 1] = 1;
        helper(grid, row, col, y, x + 1, cnt + grid[y][x + 1]);
        tags[y][x + 1] = 0;
    }

    if(proc == false)
    {
        max = MMAX(max, cnt);
    }
}

// 【算法思路】DFS + que。经典DFS题型，题目中最多25个点有黄金，所以遍历所有即可
// 注意其他题解中只遍历端点+转角，无法解决“日”字形金矿
int getMaximumGold(int** grid, int gridSize, int* gridColSize){
    int row = gridSize;
    int col = gridColSize[0];

    max = 0;
    //开始遍历
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if(grid[i][j] != 0)
            {
                tags[i][j] = 1;
                helper(grid, row, col, i, j, grid[i][j]);
                tags[i][j] = 0;
            }
        }
    }

    return max;
}


// @lc code=end


```