### 解题思路
此处撰写解题思路

### 代码

```java
/*递归，输入25*9时超出时间限制

class Solution {
    public int uniquePaths(int m, int n) {
        if (m == 1 && n == 1)   return 1;
        else if (m > 1 && n == 1)   return uniquePaths(m - 1, 1);
        else if (m == 1 && n > 1)   return uniquePaths(1, n - 1);
        else    return uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
    }
}

*/

//动态规划
class Solution {
    public int uniquePaths(int m, int n) {
        int[][] helper = new int[m + 1][n + 1];
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == 1 && j == 1)   helper[i][j] = 1;
                else if (i > 1 && j == 1)   helper[i][j] = helper[i - 1][1];
                else if (i == 1 && j > 1)   helper[i][j] = helper[1][j - 1];
                else helper[i][j] = helper[i - 1][j] + helper[i][j - 1];
            }
        }
        return helper[m][n];
    }
}
```