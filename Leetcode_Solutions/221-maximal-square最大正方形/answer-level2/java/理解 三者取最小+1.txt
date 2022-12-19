### 理解 min(上, 左, 左上) + 1
如题，动态规划方法的题解中，都会涉及到下列形式的代码：
```java
if (grid(i, j) == 1) {
    dp(i, j) = min(dp(i-1, j), dp(i, j-1), dp(i-1, j-1)) + 1;
}
```
翻译成中文
> 若某格子值为 `1` ，则以此为**右下角**的正方形的、最大边长为：上面的正方形、左面的正方形或左上的正方形中，最小的那个，再加上此格。

先来阐述简单共识
- 若形成正方形（非单 `1`），以当前为右下角的视角看，则需要：当前格、上、左、左上都是 `1`
- 可以换个角度：当前格、上、左、左上都不能受 `0` 的限制，才能成为正方形


![image.png](https://pic.leetcode-cn.com/8c4bf78cf6396c40291e40c25d34ef56bd524313c2aa863f3a20c1f004f32ab0-image.png)


上面详解了 三者取最小 的含义：
- 图1：受限于左上的0
- 图2：受限于上边的0
- 图3：受限于左边的0
- 数字表示：以此为正方形右下角的最大边长
- 黄色表示：格子 `?` 作为右下角的正方形区域

就像 **[木桶的短板理论](https://baike.baidu.com/item/%E7%9F%AD%E6%9D%BF%E7%90%86%E8%AE%BA)** 那样——附近的最小边长，才与 `?` 的最长边长有关。
此时已可得到递推公式 `if (grid[i][j] == 1) f[i][j] = min(f[i-1][j-1], f[i-1][j], f[i][j-1]) + 1;`

```java
public int maximalSquare(char[][] matrix) {
    // base condition
    if (matrix == null || matrix.length < 1 || matrix[0].length < 1) return 0;

    int height = matrix.length;
    int width = matrix[0].length;
    int maxSide = 0;

    // 相当于已经预处理新增第一行、第一列均为0
    int[][] dp = new int[height + 1][width + 1];

    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            if (matrix[row][col] == '1') {
                dp[row + 1][col + 1] = Math.min(Math.min(dp[row + 1][col], dp[row][col + 1]), dp[row][col]) + 1;
                maxSide = Math.max(maxSide, dp[row + 1][col + 1]);
            }
        }
    }
    return maxSide * maxSide;
}
```

### 理解优化技巧
- 为了避免到边的判断处理，在最左侧加上一列 `f[i][0] = 0` ，在左上边加上一行 `f[0][j] = 0` ，这才有了官方题解中所谓的 `matrix[i-1][j-1] == '1'` 与 `dp[i][j]` ，其实都是指可对应上的"当前格子"
- 其实只需关注"当前格子的周边"，故可二维降一维优化
  - 增加 `northwest` 西北角解决"左上角"的问题，感谢 [@less](https://leetcode-cn.com/u/less-9/) 指出之前缺漏的 遍历每行时，还原回辅助的原值0 的问题 `northwest = 0;` 
```java
public int maximalSquare(char[][] matrix) {
    // base condition
    if (matrix == null || matrix.length < 1 || matrix[0].length < 1) return 0;

    int height = matrix.length;
    int width = matrix[0].length;
    int maxSide = 0;

    // 相当于已经预处理新增第一行、第一列均为0
//  int[][] dp = new int[height + 1][width + 1];
    int[] dp = new int[width + 1];
    int northwest = 0; // 西北角、左上角

//  for (int row = 0; row < height; row++) {
    for (char[] chars : matrix) {
        northwest = 0; // 遍历每行时，还原回辅助的原值0
        for (int col = 0; col < width; col++) {
            int nextNorthwest = dp[col + 1];
            if (chars[col] == '1') {
//              dp[row + 1][col + 1] = Math.min(Math.min(dp[row + 1][col], dp[row][col + 1]), dp[row][col]) + 1;
                dp[col + 1] = Math.min(Math.min(dp[col], dp[col + 1]), northwest) + 1;

//              maxSide = Math.max(maxSide, dp[row + 1][col + 1]);
                maxSide = Math.max(maxSide, dp[col + 1]);
            } else {
                dp[col + 1] = 0;
            }
            northwest = nextNorthwest;
        }
    }
    return maxSide * maxSide;
}
```