[Leetcode-Java(200+题解，持续更新、欢迎star&留言&交流)](https://github.com/pphdsny/Leetcode-Java/blob/master/src/pp/arithmetic/leetcode/_74_searchMatrix.java)

```java
    /**
     * 解题思路：
     * 整个矩阵类似一个有序的升序数组，考虑使用二分查找是否存在目标值
     * 难点：中间点的计算
     * 1.利用公式计算起点和终点之间的差：(ex - sx) * col + ey - sy，
     * 2.中间点距离起点的步数：ml = ((ex - sx) * col + ey - sy) / 2
     * 3.mx = sx + (ml + sy) / col <== 起点+偏移计算出中间点的x
     * 4.my = ml + sy - (mx - sx) * col <== 根据第一步的公式，代入mx，计算出my
     * 5.利用二分查找的规则判断出结果
     *
     * 执行用时 :0 ms, 在所有 java 提交中击败了100.00%的用户
     * 内存消耗 :42.6 MB, 在所有 java 提交中击败了39.56%的用户
     *
     * @param matrix
     * @param target
     * @return
     */
    public boolean searchMatrix(int[][] matrix, int target) {
        if (matrix == null || matrix.length == 0) return false;
        int row = matrix.length;
        int col = matrix[0].length;
        if (col == 0) return false;
        int sx = 0, sy = 0, ex = row - 1, ey = col - 1;
        if (target < matrix[sx][sy] || target > matrix[ex][ey]) return false;
        int mx, my, ml;
        while (sx * col + sy <= ex * col + ey) {
            //计算中间点
            ml = ((ex - sx) * col + ey - sy) / 2;
            mx = sx + (ml + sy) / col;
            my = ml + sy - (mx - sx) * col;
            int middle = matrix[mx][my];
            if (middle == target) return true;
            //防止无法退出
            if (ml == 0) {
                if (matrix[ex][ey] == target) return true;
                return false;
            }
            if (middle > target) {
                ex = mx;
                ey = my;
            } else {
                sx = mx;
                sy = my;
            }
        }

        return false;
    }
```