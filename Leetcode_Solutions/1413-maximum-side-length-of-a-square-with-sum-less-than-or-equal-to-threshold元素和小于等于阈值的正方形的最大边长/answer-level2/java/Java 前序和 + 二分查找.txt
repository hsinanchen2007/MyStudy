### 解题思路
前序和是计算中间一段数据的和的好工具，上一次遇到是 [1171. 从链表中删去总和值为零的连续节点](https://leetcode-cn.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/) 

从一维升级到二维也是可以类比推之的。

二分查找处理起来也比较麻烦。经过这次考虑，和参考其它人的代码，我大概确定了几个注意点：
- 尽量保持边界的情况在每次循环中不变。在此解法中，minLen 是满足条件的一个边长；maxLen 是不确定是否满足条件的边长
- 循环退出时，一般是边界相交了。此解法中是 minLen == maxLen。此时应注意避免无限循环。

### 代码

```java
class Solution {
    public int maxSideLength(int[][] mat, int threshold) {
        int m = mat.length;
        int n = mat[0].length;

        // 长度 + 1，就不用考虑第一行、第一列的特殊情况了，真棒！
        // 矩形元素和sum[i][j]：以矩阵 mat 中 (0, 0), (i - 1, j - 1)为顶点的矩形的元素之和
        int[][] sum  = new int[m + 1][n + 1];
        int minLen = 0;

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + mat[i - 1][j - 1];

                if (mat[i - 1][j - 1] <= threshold) {
                    minLen = 1;
                }
            }
        }

        // 矩形中的每一个元素均大于阈值，故不存在元素和小于阈值的正方形
        if (minLen == 0) {
            return 0;
        }

        int maxLen = Math.min(m, n);

        while (minLen < maxLen) {
            int chkLen = (minLen + maxLen + 1) / 2;

            boolean has = false;

            // 考察所有边长为 chkLen 的正方形元素和
            outLoop:
            for (int i = chkLen; i <= m; i++) {
                for (int j = chkLen; j <= n; j++) {
                    // 计算以 mat[i-1][j-1] 为右下角、边长为 chkLen 的正方形元素和
                    int area = sum[i][j] - sum[i][j - chkLen] - sum[i - chkLen][j] + sum[i - chkLen][j - chkLen];

                    if (area <= threshold) {
                        has = true;
                        break outLoop;
                    }
                }
            }

            if (has) {
                minLen = chkLen;
            } else {
                maxLen = chkLen - 1;
            }
        }

        return minLen;
    }
}
```