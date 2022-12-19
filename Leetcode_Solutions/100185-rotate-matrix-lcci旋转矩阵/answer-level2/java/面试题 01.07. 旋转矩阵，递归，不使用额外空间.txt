#### 解题思路
1、对于每个格子 (i, j)，它旋转 4 次 90°以后回到原来的位置。所以可以把(i, j)旋转4次，依次更新4个位置的旋转数据。
```
1, x, x      x, x, 1      x, x, x      x, x, x     1, x, 1
x, x, x  ->  x, x, x  ->  x, x, x  ->  x, x, x  -> x, x, x
x, x, x      x, x, x      x, x, 1      1, x, x     1, x, 1
```
2、那么对于第一列，也可以把它旋转 4 次 90°，更新完**矩阵最外圈**的数据。
这样就留下了内层的 $(N-2)*(N-2)$ 大小的矩阵待处理。
```
1, 2, x      x, x, 1      x, x, x      x, x, x     1, 2, 1
x, x, x  ->  x, x, 2  ->  x, x, x  ->  2, x, x  -> 2, x, 2
x, x, x      x, x, x      x, 2, 1      1, x, x     1, 2, 1
```
3、显然，步骤2 留下的内层矩阵可以接着按照 步骤2 的方法**递归**处理。 
（$1*1$ 的矩阵比较特殊，不用旋转，但不影响结果。）


#### 例子
拿以下这个 $4*4$ 的 矩阵旋转举例
```
5, 1, 9, 11
2, 4, 8, 10
13, 3, 6, 7
15, 14, 12, 16
```


1) 先把一个 $4*4$ 的矩阵的外层旋转，内层留下以下  $2*2$的矩阵还是原来的样子。
```
rotate inner matrix: size=4, start=(0,0) end=(4,4)
5, 1, 9, 11
2, 4, 8, 10
13, 3, 6, 7
15, 14, 12, 16

外圈旋转完成
15, 13, 2, 5
14, x, x, 1
12, x, x, 9
16, 7, 10, 11

待旋转的矩阵
x, x, x, x
x, 4, 8, x
x, 3, 6, x
x, x, x, x
```

2、 递归的旋转内层 $2*2$ 的矩阵
```
rotate inner matrix: size=2, start=(1,1) end=(3,3)
x, x, x, x
x, 4, 8, x
x, 3, 6, x
x, x, x, x

外圈旋转完成
x, x, x, x
x, 3, 4, x
x, 6, 8, x
x, x, x, x
---------
```

### 代码

```java
class Solution {
   public void rotate(int[][] matrix) {
        int N = matrix.length;
        for (int k = 0; k < N; k += 2) {
            int M = N - k;
            int i = k/2;
            // System.out.println("rotate inner matrix: size=" + M + ", start=(" + i + "," + i + ") end=(" + (i+M) + "," + (i+M) + ")");
            // 旋转 matrix 的最外层
            // 相当于旋转第一行
            for (int j = 0; j < M - 1; ++j) {
                rotateCycle(matrix, i, j+i, N);
            }
        }
    }

    /**
     * 把 i,j 按照90度转一圈
     *
     * @param matrix
     * @param i
     * @param j
     */
    private void rotateCycle(int[][] matrix, int i, int j, int N) {
        // System.out.println("rotate: " + i + "," + j);
        int nextI = j;
        int nextJ = N-1-i;
        int tmp = matrix[i][j];
        while (nextI != i || nextJ != j) {
            // System.out.println("update: " + nextI + ", " + nextJ + " to " + tmp);
            int nextTmp = matrix[nextI][nextJ];
            matrix[nextI][nextJ] = tmp;
            tmp = nextTmp;
            int tmpI = nextI;
            nextI = nextJ;
            nextJ = N-1-tmpI;
        }
        // System.out.println("update: " + i + ", " + j + " to " + tmp);
        matrix[i][j] = tmp;
    }
}
```