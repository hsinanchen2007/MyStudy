### 解题思路
![image.png](https://pic.leetcode-cn.com/f39efce781e816dc54d166a2af89814c09ab7971665f5fa4de3d6c1e4ddd7c6d-image.png)

当起点明确为[0,0]的时候，就是说只用访问两个方向，下和右，此时已经包含了所有结果，当然还存在重复的结果，将重复的结果进行标记即可。

### 代码

```java
class Solution {
       public int movingCount(int m, int n, int k) {

        int[][] visited = new int[m][n];
        return dfs(0, 0, m, n, visited, k);
    }

    private int dfs(int i, int j, int m, int n, int[][] visited, int k) {
        if (add(i, j) > k || i > m - 1 || j > n - 1 || visited[i][j] == 1) {
            return 0;
        }
        visited[i][j] = 1;
        return 1 + dfs(i + 1, j, m, n, visited, k) + dfs(i, j + 1, m, n, visited, k); //这里+1是因为默认0，0是可以访问到的
    }

    private int add(int a, int b) {
        int result = 0;
        while (a != 0) {
            result += a % 10;
            a /= 10;
        }
        while (b != 0) {
            result += b % 10;
            b /= 10;
        }
        return result;
    }

}
```