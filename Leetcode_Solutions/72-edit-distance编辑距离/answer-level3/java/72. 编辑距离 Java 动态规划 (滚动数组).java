### 解题思路

动态规划  

定义状态: f[i][j] 表示 word1[0~i-1] 和 word2[0~j-1] 的编辑距离  

状态转移: 根据 word1[i-1] == word2[j-1] 分两种情况讨论  

- false: `f[i][j] = min(f[i-1][j], f[i][j-1], f[i-1][j-1]) + 1`
- true: `f[i][j] = min(f[i-1][j-1], false时的三种情况)` 

其中 false 中的三种情况依次对应删除 word1[i], 添加 word2[j], 修改 word1[i] 为 word2[j]  

边界状态: f[0][j] = j, f[i][0] = i  

优化: 使用滚动数组优化空间

### 代码

```java
/**
 * 动态规划
 * 定义状态: f[i][j] 表示 word1[0~i-1] 和 word2[0~j-1] 的编辑距离
 * 状态转移: 根据 word1[i-1] == word2[j-1] 分两种情况讨论
 *          - false: f[i][j] = min(f[i-1][j], f[i][j-1], f[i-1][j-1]) + 1
 *          - true: f[i][j] = min(f[i-1][j-1], false时的三种情况)
 *          其中 false 中的三种情况依次对应删除 word1[i], 添加 word2[j], 修改 word1[i] 为 word2[j]
 * 边界状态: f[0][j] = j, f[i][0] = i
 * 优化: 使用滚动数组优化空间
 */
class Solution {
    public int minDistance(String word1, String word2) {
        int n = word1.length();
        int m = word2.length();
        if (n == 0 || m == 0) {
            return Math.max(n, m);
        }
        int[][] f = new int[2][m + 1];
        for (int j = 0; j <= m; j++) {
            f[0][j] = j;
        }
        for (int i = 1; i <= n; i++) {
            int cur = i % 2;
            int pre = 1 - cur;
            f[cur][0] = i;  // 使用滚动数组不要忘了初始化
            for (int j = 1; j <= m; j++) {
                f[cur][j] = 0x3f3f3f3f;
                // true
                if (word1.charAt(i - 1) == word2.charAt(j - 1)) {
                    f[cur][j] = f[pre][j - 1];
                }
                // false
                f[cur][j] = Math.min(f[cur][j], f[pre][j] + 1);
                f[cur][j] = Math.min(f[cur][j], f[cur][j - 1] + 1);
                f[cur][j] = Math.min(f[cur][j], f[pre][j - 1] + 1);
            }
        }
        return f[n % 2][m];
    }
}
```