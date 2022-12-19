**思路**
1）我们可以知道，一个$n*n$的矩阵中的所有子正方形个数为$n(n+1)(2n+1)/6$，大概是$n^3$量级的。$m*n$同理。 然后题目中$1 <= m, n <= 300。300^3$的时间复杂度理论上还是可以接受的。然后至于如何暴力枚举呢，就是遍历矩阵中的每个点，以当前点为正方形左上角顶点然后不断往右下延伸，即可生成以当前点为正方形左上角顶点的所有正方形。当遍历完矩阵中所有的点后，就相当于遍历了矩阵中的所有的子正方形。而遍历过程中，我们不断更新满足条件（子正方形的元素和 $<= threshold$）的边长的最大值即是所要求的答案。

2）这里在往右下角遍历过程中，新正方形的元素和，其实是他左上角那个正方形的元素和加上两条边的元素和，如下图所示，绿色方框的正方形元素和等于红色正方形的元素和加上两条红色边的元素和减去右下角元素的值（因为右下角元素是两条红边相交的元素，即被多计算了1次）。其中两条红边的和其实可以先预处理计算得到（横边的和就是行上的两个前缀和之差，竖边就是列上的两个前缀和之差）。

![image.png](https://pic.leetcode-cn.com/5f82950f1b6b9d654658c2010d9644f6e8a499b3ed8c66feab6a62666b025d7a-image.png)

```java
public int maxSideLength(int[][] mat, int threshold) {
        int m = mat.length;
        int n = mat[0].length;

        // 每行各个元素的前缀和
        int[][] rowPrevSumArr = new int[m][n+1];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                rowPrevSumArr[i][j+1] = rowPrevSumArr[i][j] + mat[i][j];
            }
        }

        // 每列各个元素的前缀和
        int[][] colPrevSumArr = new int[m+1][n];
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++) {
                colPrevSumArr[i+1][j] = colPrevSumArr[i][j] + mat[i][j];
            }
        }

        int ansMax = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int sum = 0;
                int len = 0;
                // 从当前顶点向右下角扩展出新的正方形。
                for (int k = 0; i + k < m && j + k < n; k++) {
                    int newI = i + k;
                    int newJ = j + k;
                    int rowSum = rowPrevSumArr[newI][newJ + 1] - rowPrevSumArr[newI][j];
                    int colSum = colPrevSumArr[newI+1][newJ] - colPrevSumArr[i][newJ];
                    sum += rowSum + colSum - mat[newI][newJ];
                    if (sum > threshold) {
                        break;
                    }
                    len++;
                }

                if (len > ansMax) {
                    ansMax = len;
                }
            }
        }

        return ansMax;
    }
```

**复杂度**
时间复杂度：$O(m*n*min(m, n))$, 当$m$等于$n$的时候，可以认为是$O(n^3)$量级
空间复杂度：$O(m*n)$
