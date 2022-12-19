服了嗷，做了半天，发现是char数组。欲哭无泪。
```java
class Solution {
    public int maximalSquare(char[][] matrix) {
        int row = matrix.length,
            col = row > 0 ? matrix[0].length : 0;

        int[] dp = new int[col + 1];


        int ans = 0;

        for(int i = 0; i < row; i++) {
            int pre = 0;//记录对角的数
            for(int j = 0; j < col; j++) {
                int temp = dp[j + 1];//作为下一个的对角数先取出
                if(matrix[i][j] == '1') {
                    dp[j + 1] = Math.min(Math.min(dp[j+1],pre),
                        dp[j])+1;
                    ans = Math.max(dp[j + 1],ans);
                }else{
                    dp[j+1] = 0;
                }
                pre = temp;//对角数
            }
        }

        return ans * ans;
    }
}
```
