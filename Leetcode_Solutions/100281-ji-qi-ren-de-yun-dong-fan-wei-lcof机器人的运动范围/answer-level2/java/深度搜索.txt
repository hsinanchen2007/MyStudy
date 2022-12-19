### 解题思路
```
深搜函数：dfs(某种数据结构-树/数组等，当前位置，其他条件-辅助得到想要结果/边界条件)
1. 设置visited标志位，记录访问过的位置
2. 从起点沿右、下两个方向进行深度搜索
3. 所有方向能遍历的格子数加上当前位置即为运动范围
dfs(visited, i + dirs[0][0], j + dirs[0][1], count, k) + dfs(visited, i + dirs[1][0], j + dirs[1][1], count, k) + 1
```

### 代码

```java
public class Solution {
    public int movingCount(int m, int n, int k) {
        boolean[][] visited = new boolean[m][n];
        int count = 0;

        count = dfs(visited, 0, 0, count, k);
        return count;
    }

    private int dfs(boolean[][] visited, int i, int j, int count, int k) {
        // 判断是否深度搜索完成
        // 1. i，j是否越界
        // 2. 行坐标和列坐标的数位之和大于k
        // 3. 已经访问过
        if (i < 0 || i >= visited.length
                || j < 0 || j >= visited[0].length
                || isBigger(i, j, k) || visited[i][j]) {
            return 0;
        }
        // 因为起点为(0, 0)，需要判断右边和下边两个方向
        int[][] dirs = {{1, 0}, {0, 1}};
        // 访问过标记置1
        visited[i][j] = true;
        // 深度遍历，为所有方向之和
        count = dfs(visited, i + dirs[0][0], j + dirs[0][1], count, k)
                + dfs(visited, i + dirs[1][0], j + dirs[1][1], count, k) + 1;
        return count;
    }

    /**
     * 判断行坐标和列坐标的数位之和大于k
     * @param i 行坐标
     * @param j 列坐标
     * @param k k
     * @return 大于k返回true，否则返回false
     */
    private boolean isBigger(int i, int j, int k) {
        // x轴，y轴
        int sum = 0;
        while (i / 10 != 0) {
            sum += i % 10;
            i /= 10;
        }
        sum += i;

        while (j / 10 != 0) {
            sum += j % 10;
            j /= 10;
        }
        sum += j;
        return sum > k ? true : false;
    }
}
```

### 测试用例
```java
public class SolutionTest {
    Solution solution = new Solution();

    @Test
    public void movingCount() {
        int m1 = 2, n1 = 3, k1 = 1;
        int expect1 = 3;
        int output1 = solution.movingCount(m1, n1, k1);

        assertEquals(expect1, output1);

        int m2 = 3, n2 = 1, k2 = 0;
        int expect2 = 1;
        int output2 = solution.movingCount(m2, n2, k2);

        assertEquals(expect2, output2);

        int m3 = 16, n3 = 8, k3 = 4;
        int expect3 = 15;
        int output3 = solution.movingCount(m3, n3, k3);

        assertEquals(expect3, output3);
    }
}
```