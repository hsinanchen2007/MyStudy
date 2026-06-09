### 解题思路
就是正常使用 DFS ，这里主要针对位数和优化一下(这里的优化针对题目 100 以内的数字哦)

对于横坐标或纵坐标，下一次位数和是上一次位数和的：
1. 如果不进制，则直接上次位数和 +1，比如 11 到 12，就是1 + 1 + 1
2. 如果进制，则上次位数和 -8，比如 19 到 20，就是 1 + 9 - 8

这样就优化了大部分答案中，两次求余 + 两次除法的操作。
以下代码双百，执行 0ms。x、y 坐标，xx、yy 对应的位数和。

### 代码

```java
class Solution {
    private boolean[][] arr;

    public int movingCount(int m, int n, int k) {
        this.arr = new boolean[m][n];
        return movingCountHelper(m, n, k, 0, 0, 0, 0);
    }

    int movingCountHelper(int m, int n, int k, int x, int y, int xx, int yy) {
        if (x >= m || y >= n || xx + yy > k || arr[x][y]) return 0;
        arr[x][y] = true;
        return 1
                + movingCountHelper(m, n, k, x + 1, y, (x + 1) % 10 == 0 ? xx - 8 : xx + 1, yy)
                + movingCountHelper(m, n, k, x, y + 1, xx, (y + 1) % 10 == 0 ? yy - 8 : yy + 1);
    }
}
```