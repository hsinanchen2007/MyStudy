```
class Solution {
    public int maxDistance(int[][] grid)
    {
        int now = 1;
        boolean has0 = true;
        boolean has1 = true;
        while (has0 && has1)
        {
            has0 = false;
            has1 = false;
//查有没有1或者有没有0；
            for (int i = 0; i < grid.length; i++)
            {
                for (int j = 0; j < grid[0].length; j++)
                {
                    //System.out.println(Arrays.deepToString(grid));
                    if (grid[i][j] == now)
                    {
                        addNum(grid, now + 1, i + 1, j);
                        addNum(grid, now + 1, i - 1, j);
                        addNum(grid, now + 1, i, j + 1);
                        addNum(grid, now + 1, i, j - 1);
                        has1 = true;
//上下左右找，如果是陆地的，或者已经被标号的海洋，就算了，如果是未标号的海洋，将他标记
                    }
                    else if (grid[i][j] == 0)
                    {
                        has0 = true;
                    }
                }
            }
            now++;
        }
        int max = 0;
        for (int[] ints : grid) {
            for (int j = 0; j < grid[0].length; j++) {
                max = Math.max(max, ints[j]);
            }
        }
//找到最大的数字即可
        return max - 1 <= 0 ? - 1 : max - 1;
    }
    public void  addNum(int[][] grid,int num,int i ,int j)
    {
        if (i >= 0 && i < grid.length && j >= 0 && j < grid[0].length && grid[i][j] == 0)
        {
            grid[i][j] = num;
        }
    }
}
```