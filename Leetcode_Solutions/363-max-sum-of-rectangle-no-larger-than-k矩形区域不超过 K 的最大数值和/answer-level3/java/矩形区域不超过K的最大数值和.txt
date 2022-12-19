>欢迎大家关注我的LeetCode代码仓：[https://github.com/617076674/LeetCode]()
>几乎所有题目都会提供多种解法，真诚求star！

# 前缀和 + ceil()函数二分查找

时间复杂度是O(m * log(m) * n ^ 2)，其中m是矩阵matrix的行数，n是矩阵matrix的列数。

执行用时：179ms，击败56.30%。消耗内存：41.7MB，击败93.90%。

```java
public class Solution {
    public int maxSumSubmatrix(int[][] matrix, int k) {
        int m = matrix.length, n = matrix[0].length, result = Integer.MIN_VALUE;
        int[][] sum = new int[m][n];
        for (int i = 0; i < m; i++) {
            sum[i][0] = matrix[i][0];
        }
        for (int i = 0; i < m; i++) {
            for (int j = 1; j < n; j++) {
                sum[i][j] = sum[i][j - 1] + matrix[i][j];
            }
        }
        for (int left = 0; left < n; left++) {
            for (int right = left; right < n; right++) {
                int curSum = 0, curMax = Integer.MIN_VALUE;
                TreeSet<Integer> set = new TreeSet<>();
                set.add(0);
                for (int i = 0; i < m; i++) {
                    curSum += sum[i][right];
                    if (left > 0) {
                        curSum -= sum[i][left - 1];
                    }
                    Integer another = set.ceiling(curSum - k);
                    if (null != another) {
                        curMax = Math.max(curMax, curSum - another);
                    }
                    set.add(curSum);
                }
                result = Math.max(result, curMax);
            }
        }
        return result;
    }
}
```