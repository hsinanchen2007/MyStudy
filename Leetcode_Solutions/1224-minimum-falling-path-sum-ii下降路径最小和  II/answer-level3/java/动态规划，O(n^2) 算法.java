# 思路
题目要求所有路径的最小值，并且路径上相邻行选择的数不能是同一列。我们可以从上往下逐行遍历计算到当前行每个元素路径和的最小值，具体步骤如下：
1. 第一行每个元素的路径最小值就是数组元素本身；
```java
        for (int j = 0; j < n; j++) {
            dp[0][j] = arr[0][j];
        }
```   
2. 第二行之后每个元素的值就跟上一行除当前列路径最小值有关系。
```java
       for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int prevRowMin = prevRowMinArr[j];
                dp[i][j] = prevRowMin + arr[i][j];
            }
            prevRowMinArr = getPrevRowMinArr(dp, i);
        }
```
说明：这里计算上一行的的各个位置（除了自己）的路径和最小值做了预处理。这样就将复杂度由O(n^3)降到了O(n^2)
3. 最后计算最后一行的每个元素的路径和最小值即是答案：
```java
        int ans = Integer.MAX_VALUE;
        for (int j = 0; j < n; j++) {
            ans = Math.min(ans, dp[n-1][j]);
        }
```
完整代码如下：

```java
private int[] getPrevRowMinArr(int[][] dp, int i) {
        int n = dp.length;
        int[] minArr = new int[n]; // 除自己之外的最小值
        // 先求最小的两个数
        int min = Integer.MAX_VALUE;
        int minIndex = -1;
        for (int j = 0; j < n; j++) {
            if (dp[i][j] < min) {
                min = dp[i][j];
                minIndex = j;
            }
        }

        int secondMin = Integer.MAX_VALUE;
        for (int j = 0; j < n; j++) {
            if (j != minIndex && dp[i][j] < secondMin) {
                secondMin = dp[i][j];
            }
        }

        for (int j = 0; j < n; j++) {
            if (j == minIndex) {
                minArr[j] = secondMin;
            } else {
                minArr[j] = min;
            }
        }

        return minArr;
    }

    public int minFallingPathSum(int[][] arr) {
        int n = arr.length;
        int[][] dp = new int[n][n];

        for (int j = 0; j < n; j++) {
            dp[0][j] = arr[0][j];
        }

        // 记录上一行的每个位置除自己外的最小值
        int[] prevRowMinArr = getPrevRowMinArr(dp, 0);

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int prevRowMin = prevRowMinArr[j];
                dp[i][j] = prevRowMin + arr[i][j];
            }
            prevRowMinArr = getPrevRowMinArr(dp, i);
        }

        int ans = Integer.MAX_VALUE;
        for (int j = 0; j < n; j++) {
            ans = Math.min(ans, dp[n-1][j]);
        }

        return ans;
    }
```
# 复杂度
**时间复杂度**：$O(n^2)$
**空间复杂度**：$O(n^2)$