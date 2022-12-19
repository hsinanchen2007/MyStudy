### 解题思路
三种解题方法，具体看注释。

### 代码

```java
class Solution {
    private char[][] matrix;
    public int findSquare(int row, int col, int height, int width){
       if (matrix[row][col] == '0')
           return 0;
       int min = Integer.MAX_VALUE;
       int max = 0;
       int i,j;
       j = row;
       while (j < height && j-row < min){
           i = col;
           while (i < width && i-col< min){
               if (matrix[j][i] == '0')
                   break;
               i++;
           }
           min = min > i - col ? i-col : min;
           j++;
           max = Math.max(max, Math.min(j - row, i - col));
       }
       return max;
    }
    public int maximalSquareNorma(char[][] matrix) {
        if (matrix == null || matrix.length == 0)
            return 0;
        this.matrix = matrix;
        int max = 0;
        for (int i = 0; i < matrix.length; i++)
            for (int j = 0; j < matrix[0].length; j++){
               if (matrix[i][j] == '1') {
                   max = Math.max(max, findSquare(i, j, matrix.length, matrix[0].length));
               }
            }

        return max*max;
    }

    /**
     * 动态规划
     * 假设最简单的正方形是 是4个点组成，当前点正方形，由其左上，上，左，决定
     * 当前点的正方形，当前节点之前的点可以组成的正方形是可以求出来的，下一个节点
     * 依赖前一个节点。
     * dp[i][j] = Math.min(dp[i-1, j -1), dp[i-1][j], dp[i][j-1])
     * 时间复杂度 O （m * n) , 空间复杂度 O（m * n)
     * @param matrix
     * @return
     */
    public int maximalSquareDy(char[][] matrix) {
        if (matrix == null || matrix.length == 0)
            return 0;
        int row = matrix.length + 1;
        int col = matrix[0].length + 1;
        // 因为都是 i-1，所以长度加1，从1开始，因为 i =0时， 下标-1不存在，还要单独判断
        int[][] dp = new int[row][col];
        int max = 0;
        for (int i = 1; i < row; i++)
            for (int j = 1; j < col; j++){
                if (matrix[i -1][j-1] == '1'){
                    dp[i][j] = (Math.min(dp[i][j-1], Math.min(dp[i-1][j-1], dp[i-1][j]))) + 1;
                   max = Math.max(max, dp[i][j]) ;
                }
            }
        return max * max;
    }

    /**
     * 观察发现，只使用了, 上一行和左边的值，所以只需要存上一行和左边的值
     * @param matrix
     * @return
     */
    public int maximalSquare(char[][] matrix) {
        if (matrix == null || matrix.length == 0)
            return 0;
        int row = matrix.length + 1;
        int col = matrix[0].length + 1;
        // 因为都是 i-1，所以长度加1，从1开始，因为 i =0时， 下标-1不存在，还要单独判断
        int[] dp = new int[col];
        int max = 0;
        int pre = 0;
        int temp;
        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                // dp[j] 记录的第i-1行的值，下次循环作为pre使用，因为dp[j]下次循环
                //的值是，dp[i][j-1]的值，
                temp = dp[j];
                if (matrix[i - 1][j - 1] == '1') {
                    // dp[j] 覆盖了dp[i-1][j-1],存储的是 dp[i][j-1],所以需要prev 存储dp[i-1][j-1]
                    dp[j] = (Math.min(pre, Math.min(dp[j - 1], dp[j]))) + 1;
                    max = Math.max(max, dp[j]);
                } else {
                    //因为使用pre存储，左边的值，所以当当前节点为0时，当前节点正方形为0
                    dp[j] = 0;
                }
                pre = temp;
            }
            pre = 0;
        }
        return max * max;
    }
    @Test
    public void test(){
        char[][] matrix = new char[][] {
        {'1','0','1','0'}
        ,{'1','0','1','1'}
        ,{'1','0','1','1'}
        ,{'1','1','1','1'}};
        Assertions.assertEquals(4, maximalSquare(matrix));
         matrix = new char[][]{
         {'1' ,'0' ,'1' ,'0' ,'0'}
        ,{'1' ,'0' ,'1' ,'1' ,'1'}
        ,{'1' ,'1' ,'1' ,'1' ,'1'}
        ,{'1' ,'0' ,'0' ,'1' ,'0'}};
        Assertions.assertEquals(4, maximalSquare(matrix));
        matrix = new char[][]{ {}};
        Assertions.assertEquals(0, maximalSquare(matrix));
        matrix = new char[][]{ {'0'}};
        Assertions.assertEquals(0, maximalSquare(matrix));
         matrix = new char[][]{ {'1' ,'0' ,'1' ,'0' ,'0'}};
        Assertions.assertEquals(1, maximalSquare(matrix));
         matrix = new char[][]{
                 {'1' ,'0' ,'1' ,'0' ,'0'}
                 ,{'1' ,'0' ,'1' ,'1' ,'1'}
                 ,{'1' ,'1' ,'1' ,'1' ,'1'}
                 ,{'1' ,'0' ,'1' ,'1' ,'0'}};
        Assertions.assertEquals(4, maximalSquare(matrix));
        matrix = new char[][]{
                {'1' ,'0' ,'1' ,'0' ,'0'}
                ,{'1' ,'0' ,'1' ,'1' ,'1'}
                ,{'1' ,'1' ,'1' ,'1' ,'1'}
                ,{'1' ,'0' ,'1' ,'1' ,'1'}};
        Assertions.assertEquals(9, maximalSquare(matrix));
    }

}
```