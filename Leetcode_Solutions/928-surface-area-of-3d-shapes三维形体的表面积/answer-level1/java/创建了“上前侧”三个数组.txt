![image.png](https://pic.leetcode-cn.com/ab8954a8c17f0d05ecd7d2f8d86ed266ee803bb271a5366fcd9715418ab891d8-image.png)

```
    int top = 0;
    int N = grid.length;
    int[] side = new int[N];
    int[] front = new int[N];
    for(int i = 0; i < N; i++) {
        int tmpSide = 0;
        for(int j = 0; j < N; j++) {
            if(grid[i][j] > 0) {
                top++;
            }
            tmpSide += (j == 0 ? grid[i][j] : (Math.max(grid[i][j] - grid[i][j - 1], 0)));
            front[j] += (i == 0 ? grid[i][j] : (Math.max(grid[i][j] - grid[i - 1][j], 0)));
        }
        side[i] = tmpSide;
    }
    int res = 0;
    for(int i = 0; i < N; i++) {
        res += side[i] + front[i];
    }
    res += top;
    return res * 2;
```
