### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    private int m;
    private int n;
    private int k;
    private int cnt;

    private boolean[][] mark;

    public int movingCount(int m, int n, int k) {
        this.m = m;
        this.n = n;
        this.k = k;
        this.cnt = 0;
        mark = new boolean[m][n];

        robotMove(0, 0);
        return cnt;
    }

    private void robotMove(int x, int y) {
        if (!canMoving(x, y))
            return;
        if (mark[x][y])
            return;
        ++cnt;
        mark[x][y] = true;
        robotMove(x+1, y);
        robotMove(x, y+1);
    }

    private boolean canMoving(int x, int y) {
        if (x < 0 || y < 0 || x >= m || y >= n)
            return false;

        if (x + y <= k)
            return true;

        int x1 = 0;
        while (x != 0) {
            x1 += x %10;
            x /= 10;
        }

        int y1 = 0;
        while (y != 0) {
            y1 += y%10;
            y /= 10;
        }
        return x1+y1 <= k;
    }

}
```