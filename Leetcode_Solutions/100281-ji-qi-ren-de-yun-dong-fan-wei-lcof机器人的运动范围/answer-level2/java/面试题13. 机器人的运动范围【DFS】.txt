### 解题思路
    典型的DFS 题目，注意边界条件即可。
    用一个函数来计算行坐标和列坐标的数位之和； 
    用一个函数判断坐标是否在表格内。

### 代码

```java
class Solution {
    /*
     * 思路：
     */
    public int movingCount(int m, int n, int k) {
        int[][] visited = new int[m][n];// 表示是否访问
        return move(0, 0, m, n, k, visited);
    }

    public int move(int x, int y, int m, int n, int k, int[][] visited) {
        int count = 0;
        if (isInGrid(x, y, m, n) && visited[x][y] != 1) {
            if (sum(x) + sum(y) <= k) {
                visited[x][y] = 1;
                count++;
                count = 1 + move(x + 1, y, m, n, k, visited)
                          + move(x - 1, y, m, n, k, visited)
                          + move(x, y + 1, m, n, k, visited)
                          + move(x, y - 1, m, n, k, visited);
            }
        }

        return count;
    }

    // 判断坐标是否在方格内
    public boolean isInGrid(int x, int y, int m, int n) {
        if (x >= 0 && x < m && y >= 0 && y < n) {
            return true;
        }
        return false;
    }

    // 行坐标和列坐标的数位之和
    public int sum(int num) {
        int s = 0;
        while (num != 0) {
            s += num % 10;
            num /= 10;
        }
        return s;
    }
}
```