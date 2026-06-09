### 解题思路
此处撰写解题思路

### 代码

```csharp
public class Solution {
    public int MovingCount(int m, int n, int k) {
          //创建二维数组
    int[][] grid = new int[m][];
    for(int i = 0; i < m; i++)
    {
        grid[i] = new int[n];
    }

    //初始化，第一个格永远都会走到
    grid[0][0] = 1; 
    int ans = 1;

    //开始查找周边
    ans += CheckAround(grid, 0, 0, k);
    return ans;
}

public int GetSum(int x, int y)
{
    //m,n <= 100所以 x,y <= 99，都不会超过两位数
    return x % 10 + x / 10 + y % 10 + y / 10;
}

public int CheckAround(int[][] grid, int x, int y, int k)
{
    int count = 0;
    if(x > 0 && grid[x - 1][y] == 0 && GetSum(x - 1, y) <= k) //上方
    {
        grid[x - 1][y]++; //将能走到的地方置为1
        count++; //结果加1
        count += CheckAround(grid, x - 1, y, k); //从相邻格继续向周围查找
    }
    if(x + 1 < grid.Length && grid[x + 1][y] == 0 && GetSum(x + 1, y) <= k) //下发
    {
        grid[x + 1][y]++;
        count++;
        count += CheckAround(grid, x + 1, y, k);
    }
    if(y > 0 && grid[x][y - 1] == 0 && GetSum(x, y - 1) <= k) //左侧
    {
        grid[x][y - 1]++;
        count++;
        count += CheckAround(grid, x, y - 1, k);
    }
    if(y + 1 < grid[x].Length && grid[x][y + 1] == 0 && GetSum(x, y + 1) <= k) //右侧
    {
        grid[x][y + 1]++;
        count++;
        count += CheckAround(grid, x, y + 1, k);
    }
    return count;
}
}

```