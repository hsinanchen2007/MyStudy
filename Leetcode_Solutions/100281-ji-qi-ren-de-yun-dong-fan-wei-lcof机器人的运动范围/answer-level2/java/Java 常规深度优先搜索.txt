### 解题思路

> 执行用时 :1 ms, 在所有 Java 提交中击败了90.45%的用户
> 内存消耗 :36.7 MB, 在所有 Java 提交中击败了100.00%的用户

因为不想写队列，所以就写深度遍历吧。当然也可以用广度遍历处理。

### 代码

```java
class Solution {
    private int[] dx = {0, 0, 1, -1};
    private int[] dy = {1, -1, 0, 0};

    public int movingCount(int m, int n, int k) {
        int[][] map = new int[m][n];
        return travel(0, 0, map, m, n, k);
    }

    private int travel(int cr, int cc, int[][] map, int m, int n, int k) {
        if(cr < 0 || cr >= m || cc < 0 || cc >= n || map[cr][cc] == 1 || !allow(cr, cc, k)) {
            return 0;
        }
        int sum = 1;
        map[cr][cc] = 1;
        for(int i = 0; i < 4; i ++) {
            sum += travel(cr + dx[i], cc + dy[i], map, m, n, k);
        }
        return sum;
    }

    private boolean allow(int m, int n, int k) {
        return sum(m) + sum(n) <= k;
    }
    
    private int sum(int n) {
        int sum = 0;
        while(n != 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
}
```