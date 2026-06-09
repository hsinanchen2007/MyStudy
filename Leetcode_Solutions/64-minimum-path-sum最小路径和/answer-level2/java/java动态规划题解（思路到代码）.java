- 先看题，可发现二维数组都成了一个表
- 例如这样
1,2,3,4,5
3,4,8,2,3
4,2,1,8,6
- 对于每一个点位，它的来源状态有两种，一是从上往下走来的，另一种是从左往右走来的
- 但是有例外，也就是我们需要考虑的边界，从上表可知12345这一行和134这一列是只有一种来源方向的，因此需要单独拉出来处理
- 同时还存在起点1，表的[0][0]位置，综上可得四种状态
- 设n为行坐标，m为列坐标
```
左上角
dp[0][0]=grid[0][0];

上边线
dp[n][0]=dp[n-1][0]+grid[n][0];
左边线
dp[0][m]=dp[0][m-1]+grid[0][m]

其它点位
dp[n][m]=math.min(dp[n-1][m]+grid[n][m],dp[n][m-1]+grid[n][m]);
```
- 状态转移方程和边界条件拿到之后就可以写代码了，两层循环，时间复杂度为n*m，即原二维数组的行列数积
```
class Solution {
    public int minPathSum(int[][] grid) {
        int[][] dp=new int[grid.length][grid[0].length];
        for(int n=0;n<grid.length;n++)
        {
            for(int m=0;m<grid[n].length;m++)
            {
                if(m==0&&n==0)
                {
                    dp[n][m]=grid[0][0];
                }
                else if(n==0)
                {
                    dp[n][m]=dp[0][m-1]+grid[0][m];
                }
                else if(m==0)
                {
                    dp[n][m]=dp[n-1][0]+grid[n][0];
                }
                else
                {
                    dp[n][m]=Math.min(dp[n-1][m]+grid[n][m],dp[n][m-1]+grid[n][m]);
                }
            }
        }
        return dp[grid.length-1][grid[0].length-1];
    }
}
```
- 这个解法在时间和空间复杂度上还有很多可以改进的地方，比如把用来存储结果的二维数组改为变量，
本题要求只需要关注当前量和之前一步的量就可以了，所以完全没有必要用二维数组来存
- 时间上也可以通过合理的设置其他的边界和剪枝来节省，这只是一个初步的思路，不多赘述了