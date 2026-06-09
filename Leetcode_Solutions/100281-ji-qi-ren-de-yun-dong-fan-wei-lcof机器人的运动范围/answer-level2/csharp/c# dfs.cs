### 解题思路
dfs

### 代码

```csharp
public class Solution {
    int toSum(int s)
    {
        int sum = 0;
        while(s != 0)
        {
            sum += s % 10;
            s /= 10;
        }
        return sum;
    }
    public int MovingCount(int m, int n, int k) {
        bool[][] grids = new bool[m][];
        for(int i = 0; i < grids.Length; i++)
        {
            grids[i] = new bool[n];
        }

        for(int i = 0; i < m; i++)
        {
            int sumI = toSum(i);
            for(int j = 0; j < n; j++)
            {
                int sumJ = toSum(j);
                grids[i][j] = sumI + sumJ <= k;
            }
        }

        if(!grids[0][0])
        {
            return 0;
        }

        int c = Search(grids, 0, 0, n, m);

        return c;
    }

    int Search(bool[][] grids, int x, int y, int n, int m)
    {
        if(x < 0 || x >= n || y < 0 || y >= m)
        {
            return 0;
        }

        if(!grids[y][x])
        {
            return 0;
        }

        int c = 1;
        grids[y][x] = false;

        int[] xOffsets = new int[]{0, 0, -1, 1};
        int[] yOffsets = new int[]{-1, 1, 0, 0};
        
        for(int i = 0; i < xOffsets.Length; i++)
        {
            int newX = x + xOffsets[i];
            int newY = y + yOffsets[i];

            c += Search(grids, newX, newY, n, m);
        }

        return c;
    }
}
```