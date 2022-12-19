动态规划
由题意得到如果matrix中为零，r为零。或者上下左右四个方向的值+1，填表。
第一遍从上到下，从左到右，填表。
第二遍从下到上，从右到左，填表。
填表过程中，边界比较特殊。
```
class Solution {
    public int[][] updateMatrix(int[][] matrix) {
        int l1 = matrix.length;
        int l2 = matrix[0].length;
        if(l1 == 0) return matrix;
        int[][] r = new int[l1][l2];
        for(int i = 0; i < l1; i++) {
            for(int j = 0; j < l2; j++) {
                r[i][j] = Integer.MAX_VALUE - 1000;//防溢出
            }
        }
        for(int i = 0; i < l1; i++) {
            for(int j = 0; j < l2; j++) {
                if(matrix[i][j] == 0)
                    r[i][j] = 0;//只更新一遍
                else {
                    if(i > 0)
                        r[i][j] = Math.min(r[i][j],r[i-1][j] + 1);
                    if(j > 0)
                        r[i][j] = Math.min(r[i][j],r[i][j-1] + 1);
                }
            }
        }
        for(int i = l1-1; i >= 0; i--) {
            for(int j = l2-1; j >= 0; j--) {
                if(i < l1-1)
                        r[i][j] = Math.min(r[i][j],r[i+1][j] + 1);
                if(j < l2-1)
                        r[i][j] = Math.min(r[i][j],r[i][j+1] + 1);
            }
        }
        return r;
    }
}
```
