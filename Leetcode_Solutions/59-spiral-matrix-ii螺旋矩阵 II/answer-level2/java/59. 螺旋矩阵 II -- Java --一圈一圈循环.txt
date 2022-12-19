[Leetcode-Java(更多题解，持续更新)](https://github.com/pphdsny/Leetcode-Java/blob/master/src/pp/arithmetic/leetcode/_59_generateMatrix.java)

```java 
    /**
     * 解题思路：
     * 通过四个变量（2个行0~n、2个列0~n），一圈一圈的遍历，每一圈遍历的时候做四个方向的遍历
     *
     * @param n
     * @return
     */
    public int[][] generateMatrix(int n) {
        int[][] matrix = new int[n][n];
        int r1 = 0, r2 = matrix.length - 1;
        int c1 = 0, c2 = matrix[0].length - 1;
        int index = 1;
        while (r1 <= r2 && c1 <= c2) {
            for (int c = c1; c <= c2; c++) matrix[r1][c] = index++;
            for (int r = r1 + 1; r <= r2; r++) matrix[r][c2] = index++;
            if (r1 < r2 && c1 < c2) {
                for (int c = c2 - 1; c > c1; c--) matrix[r2][c] = index++;
                for (int r = r2; r > r1; r--) matrix[r][c1] = index++;
            }
            r1++;
            r2--;
            c1++;
            c2--;
        }
        return matrix;
    }

```