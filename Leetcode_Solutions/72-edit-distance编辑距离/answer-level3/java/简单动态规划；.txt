### 解题思路
定义数组value来记录word1[i] 转换到 word2[j] 每一步需要的最少操作数，当word1[i]和Word2[j]当前的值相同时最小的步数为 word1[i-1] 和word2[j-1] 的最小步数值；不相等时，有三种方式word1[i] 可以到达word2[j],故取从word1[i] 到 word2[j-1]的最小步数值 和 word1[i-1] 到 word2[j] 的最小步数值 和 word1[i-1] 到 word2[j-1] 的最小步数值的最小值 + 1，故动态转移方程为：value[i][j] = word1.charAt(i-1) == word2.charAt(j-1) ? value[i-1][j-1] : Math.min(value[i][j-1] ,Math.min(value[i-1][j],value[i-1][j-1])) + 1; 


### 代码

```java
class Solution {
    public int minDistance(String word1, String word2) {
        int n = word2.length(); // 列
        int m = word1.length(); // 行
        // 记录word1[i] 转换到word[j] 需要的最少操作数
        int[][] value = new int[m+1][n+1];
        for (int i = 1; i < n+1; i++) {
            value[0][i] = value[0][i-1] + 1;
        }
        for (int i = 1; i < m+1; i++) {
            value[i][0] = value[i-1][0] + 1;
        }
        for (int i = 1; i < m+1; i++) {
            for (int j = 1; j < n+1; j++) {
                value[i][j] = word1.charAt(i-1) == word2.charAt(j-1) ? value[i-1][j-1] : Math.min(value[i][j-1] ,Math.min(value[i-1][j],value[i-1][j-1])) + 1;
            }
        }
        return value[m][n];
    }
}
```