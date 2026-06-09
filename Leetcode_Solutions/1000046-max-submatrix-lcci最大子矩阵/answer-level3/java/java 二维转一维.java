**前提**
必须知道如何在O(n)时间复杂度内求解一维数组的最大子数组和（参考[最大子数组和](https://leetcode-cn.com/problems/maximum-subarray/)）。

**思路**
假设有以下矩阵，为了图示的美观，下标从1开始。其中假设某子矩阵为$[r1, c1, r2, c2]$。
$$
\left[
 \begin{matrix}
   a[1][1] & ... & a[1][c1] & ... & a[1][c2] & a[0][n]\\
   ... & ... & ... & ... & ... & ...\\
   a[r1][1] & ... & a[r1][c1] & ... & a[r1][c2] & a[r1][n]\\
   ... & ... & ... & ... & ... & ...\\
   a[r2][1] & ... & a[r2][c1] & ... & a[r2][c2] & a[r2][n]\\
   ... & ... & ... & ... & ... & ...\\
   a[m][1] & ... & a[m][c1] & ... & a[m][c2] & a[m][n]\\
  \end{matrix} 
\right]
$$

那么，子矩阵的和即为 $(a[r1][c1] + a[r1+1][c1] + ... + a[r2][c1]) + ... + (a[r1][j] + a[r1+1][j] + ... + a[r2][j]) + ... + (a[r1][c2] + a[r1+1][c2] + ... + a[r2][c2])$ 。其中 $(a[r1][j] + a[r1+1][j] + ... + a[r2][j])$ 即为从r1行到r2行第j列上的元素之和。这个值可以通过预先求得的列上的前缀和通过$O(1)$时间求得。可以认为我们在y轴方向上压缩矩阵，变成一维数组。该一维数组的每个元素即为列上的某个区域和。然后问题就转化成求一维数组的最大子数组和。这里矩阵的上边和矩阵的下边是变化的，也就是需要m大小的二重循环，然后求一维数组的最大子数组和需要$O(n)$时间，因此总的时间复杂度为$O(m * m * n)$。具体代码如下:

```java
private int[] getMaxArray(int[] nums) {
        // 求一维数组的最大子数组和
        int len = nums.length;
        int max = nums[0];
        int maxFromCol = 0;
        int maxToCol = 0;
        int fromCol = 0;
        int preMax = nums[0];
        for (int col = 1; col < len; col++) {
            if (preMax <= 0) {
                if (nums[col] > max) {
                    max = nums[col];
                    maxFromCol = col;
                    maxToCol = col;
                }
                preMax = nums[col];
                fromCol = col;
            } else {
                preMax = preMax + nums[col];
                if (preMax > max) {
                    max = preMax;
                    maxFromCol = fromCol;
                    maxToCol = col;
                }
            }
        }

        return new int[]{max, maxFromCol, maxToCol};
    }

    // 最大子矩阵，最大子矩形
    public int[] getMaxMatrix(int[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;
        int ansMax = Integer.MIN_VALUE;
        int[] ansArr = new int[4];
        int[][] colPreSum = new int[m][n];  // 列上的前缀和

        for (int j = 0; j < n; j++) {
            colPreSum[0][j] = matrix[0][j];
            for (int i = 1; i < m; i++) {
                colPreSum[i][j] = colPreSum[i-1][j] + matrix[i][j];
            }
        }

        int[] tmpArr = new int[n];
        for (int fromRow = 0; fromRow < m; fromRow++) {
            for (int toRow = fromRow; toRow < m; toRow++) {
                // 第fromRow行到第toRow行进行合并
                for (int col = 0; col < n; col++) {
                    tmpArr[col] = fromRow == 0 ? colPreSum[toRow][col] : colPreSum[toRow][col] - colPreSum[fromRow - 1][col];
                }

                // 求一维数组的最大子数组和
                int[] maxArrayRes = getMaxArray(tmpArr);
                int max = maxArrayRes[0];
                int maxFromCol = maxArrayRes[1];
                int maxToCol = maxArrayRes[2];

                if (max > ansMax) {
                    ansMax = max;
                    ansArr[0] = fromRow;
                    ansArr[1] = maxFromCol;
                    ansArr[2] = toRow;
                    ansArr[3] = maxToCol;
                }
            }
        }

        return ansArr;
    }
```