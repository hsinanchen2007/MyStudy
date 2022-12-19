### 解题思路
通过递归，从起始元素开始，向下和向右，直至到边界值即可，易错点在于容易重复计算点位，因此需要记录已扫描过的点位
### 代码

```java
class Solution {
    boolean[][] visited;

    int reachCount = 0;

    public int movingCount(int m, int n, int k) {
        visited = new boolean[m][n];
        scan(m, n, 0, 0, k);
        return reachCount;
    }

    private void scan(int m, int n, int i, int j, int k) {
        if (i > m - 1 || j > n - 1 || i < 0|| j <0 || visited[i][j]) {
            return;
        }
        visited[i][j] = true;
        if (calcuSum(i, j) > k) {
            return;
        }

        reachCount++;
        scan(m, n, i, j + 1, k);
        scan(m, n, i + 1, j, k);
    }

    private int calcuSum(int i, int j) {
        return i/10 + i%10 + j/10 + j%10;
    }
}
```