细节题，用一个数组记录下从每个方向进和某个街道对应的出口方向，
出口方向是进入下一个街道的放方向
0 是从上往下走
1 从下往上
2 从右往左
3 从左往右
这样写就不用写太多的if case 不然代码就会像裹脚布一样ORZ
```java
    public boolean hasValidPath(int[][] grid) {
        if (grid[0][0] == 5) return false;
        ftMap = new int[4][7];
        for (int i = 0; i < ftMap.length; i++) {
            for (int j = 0; j < ftMap[0].length; j++) {
                ftMap[i][j] = -1;
            }
        }
        //往什么方向进 选择了什么街道 下一次进入其他街道的方向
        ftMap[0][2] = 0;
        ftMap[0][5] = 2;
        ftMap[0][6] = 3;
        ftMap[1][3] = 2;
        ftMap[1][4] = 3;
        ftMap[1][2] = 1;
        ftMap[2][1] = 2;
        ftMap[2][4] = 0;
        ftMap[2][6] = 1;
        ftMap[3][1] = 3;
        ftMap[3][3] = 0;
        ftMap[3][5] = 1;
        int p1 = -1;
        int p2 = -1;
        int b = grid[0][0];
        if (b == 1) p1 = 3;
        else if (b == 2) p1 = 0;
        else if (b == 3) p2 = 3;
        else if (b == 4) {
            p1 = 1;
            p2 = 2;
        } else if (b == 6) p1 = 0;
        if (p2 != -1) return help(grid, 0, 0, p1) || help(grid, 0, 0, p2);
        return help(grid, 0, 0, p1);
    }

    int[][] ftMap;

    public boolean help(int[][] grid, int x, int y, int from) {
        if (x == grid.length - 1 && y == grid[0].length - 1) return true;
        int np = ftMap[from][grid[x][y]];
        if (np == 0) x++;
        else if (np == 1) x--;
        else if (np == 2) y--;
        else y++;
        if (x < 0 || x >= grid.length || y < 0 || y >= grid[0].length || ftMap[np][grid[x][y]] == -1) return false;
        return help(grid, x, y, np);
    }
```