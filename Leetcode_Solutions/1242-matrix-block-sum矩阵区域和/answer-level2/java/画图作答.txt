这道题的核心是：求坐标(i-K,j-K)到(i+K,j+K)的元素的和，那么再去看看leetcode304，也是求某个子区域的和。

![image.png](https://pic.leetcode-cn.com/afeff2420dbe1a50f13bbc4579a2982701b0ffc89f667950ad069bcdc5410efb-image.png)

那么怎么求解呢？画图就明白了。

通过画图，想明白2件事情：

你的目标是求绿色这块区域的和，那么其实是要先计算出，**从(0,0)到绿色这块区域最右下角的(4,3)这块区域的总和 - 红色这块区域的和以及黄色这块区域的和 + 你重复减掉的红黄重叠的和**。那么你要的这块绿色的答案就出来了。

![image.png](https://pic.leetcode-cn.com/6c021f3ada6374cb1debea70a33fd4ba338b6c70ecbe8332c9d07ab6a84d855a-image.png)

这个想明白以后，那么我们在来想要怎么计算从(0,0)到每个小块的总和是多少？你可以暴力破解。但是你会发现，其实你会重复计算。
譬如，前面四个元素，你计算(1,1)时候的和，明显可以通过它的上面和它的左边的和，再加上自己的值求得。
那么再推到(0,1),(1,0),他们的和，可以是(0,0)+自己的值求的，那么(0,0)这个坐标的值被重复算了2次，你要减掉一个就是。
于是求(0,0)到某个坐标(i,j)的和就可以通过下面的方式求得。
dp[i][j] = dp[i-1][j] + dp[i][j-1] + mat[i][j] - dp[i-1][j-1]

![image.png](https://pic.leetcode-cn.com/51d80b5e5183f5a5a41f9ca6deeb948e5c5d289dedef83437222018eb1976a6a-image.png)


最后的代码如下：

```
class Solution {
    public int[][] matrixBlockSum(int[][] mat, int K) {
        //这道题就是leetcode304的变种
            int row = mat.length;
            int col = mat[0].length;
            int[][] dp = new int[row][col];
            dp[0][0] = mat[0][0];
            //处理第一行
            for(int j=1;j<col;j++){
                dp[0][j] = dp[0][j-1]+mat[0][j];
            }
            //处理第一列
            for(int i=1;i<row;i++){
                dp[i][0] = dp[i-1][0] + mat[i][0];
            }
            //先计算每个点从00到它的总和。
            for(int i=1;i<mat.length;i++){
                for(int j=1;j<mat[0].length;j++){
                    dp[i][j] = dp[i-1][j] + dp[i][j-1] + mat[i][j] - dp[i-1][j-1] ;
                }
            }
            //然后再计算从(i-k,j-k)到(i+k,j+k)的sum，再填写到ans的二维数组里去
            int[][] ans = new int[row][col];
            for(int i=0;i<row;i++){
                for(int j=0;j<col;j++)
                {
                    ans[i][j] = processing(dp,Math.max(0,i-K),Math.max(0,j-K),Math.min(row-1,i+K),Math.min(col-1,j+K));
                }
            }
            return ans;
        }
        public int processing(int[][] dp, int rowStart,int colStart, int rowEnd,int colEnd){
            return dp[rowEnd][colEnd] - (rowStart-1<0?0:dp[rowStart-1][colEnd]) - (colStart-1<0?0:dp[rowEnd][colStart-1]) + (colStart-1<0||rowStart-1<0?0:dp[rowStart-1][colStart-1]);
        }
}
```
