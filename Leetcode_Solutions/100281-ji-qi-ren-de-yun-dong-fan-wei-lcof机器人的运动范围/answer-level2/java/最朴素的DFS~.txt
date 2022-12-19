### 解题思路
毫无花哨的姿势，最朴素DFS+记忆内存。

### 代码

```java
class Solution {
    private int sumNum(int i) {
        int sum = 0;
        sum += i / 100;
        i = i % 100;
        sum += i / 10;
        i = i % 10;
        sum += i;
        return sum;
    }

    private int sumRowCol(int i, int j) {
        return sumNum(i) + sumNum(j);
    }

    public int movingCount(int m, int n, int k) {
        dfs(m, n, 0, 0, k);
        return set.size();
    }

    private Set<Integer> set = new HashSet<>();

    private void dfs(int m, int n, int i, int j, int k) {
        if (i < 0 || j < 0 || i >= m || j >= n) {
            return;
        }
        if (sumRowCol(i, j) > k) {
            return;
        }
        int index = i * n + j;
        if (set.contains(index)) {
            return;
        }
        set.add(index);
        int[][] directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        for (int[] dir : directions) {
            dfs(m, n, i + dir[0], j + dir[1], k);
        }
    }
}
```