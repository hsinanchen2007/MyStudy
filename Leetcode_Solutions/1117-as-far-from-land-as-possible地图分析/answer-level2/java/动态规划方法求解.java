### 解题思路
利用动态规划数组dp[i][j]的值表示(i,j)这个坐标位置到最近的陆地区域的面积。

1.状态转移方程很容易想到是:
        dp[i+1][j]=min(dp[i][j]+1,dp[i+1][j])
        dp[i][j+1]=min(dp[i][j]+1,dp[i][j+1])
        dp[i-1][j]=min(dp[i][j]+1,dp[i-1][j])
        dp[i][j-1]=min(dp[i][j-1]+1,dp[i][j-1])
就是利用i,j这个位置离陆地的最近面积可以更新与之相邻的坐标距离陆地的距离。
不过还需要注意是否越界的问题。

2.初始值的处理：
由于数组初始赋值的时候自动赋值为0，但是我们又在用最小值求解dp[i][j],
所以我们应当在初始赋值的时候将dp[i][j]赋值为一个较大值。
而且当grid[i][j]=1即i,j坐标是陆地的时候应当将dp[i][j]赋值为0。

3.如何遍历所有状态以求得最终解：
先从左上角向右下角遍历一遍更新dp数组，
再从右下角向左上角遍历一遍更新dp数组。
然后再遍历整个dp数组找出dp的最大值就是求得的结果，不过还要注意对全是陆地和全是海洋的情况的处理。
为什么需要两次遍历呢？
比如说有个例子：
    1，0，0，0，0
    0，0，0，0，1
那么仅从左上角或者右下角遍历都会得到最大距离为4，这显然不对。
而两次遍历取dp的最小值则可以解决这个问题。
至于两次遍历的正确性大概是因为对于一个点而言，这样的两次遍历遍历了所有方向。（不是特别清楚）

执行用时 :
8 ms
, 在所有 Java 提交中击败了
100.00%
的用户
内存消耗 :
42.4 MB
, 在所有 Java 提交中击败了
99.00%
的用户
### 代码

```java
class Solution {
    //利用动态规划的方法来解决问题
    public int maxDistance(int[][] grid) {
        int [][]dp=new int [grid.length][grid[0].length];
        int i,j;
        int res=0;//返回值res
        for(i=0;i<grid.length;i++)
            for(j=0;j<grid.length;j++)
                dp[i][j]=400;
        //定义初始值为400，这样之后取最小值就可以当作是该点到陆地的最近距离

        for(i=0;i<grid.length;i++)
            for(j=0;j<grid[0].length;j++)
            {
                if(grid[i][j]==1)
                    dp[i][j]=0;
                if(i<grid.length-1)
                    dp[i+1][j]=Math.min(dp[i][j]+1,dp[i+1][j]);
                if(j<grid[0].length-1)
                    dp[i][j+1]=Math.min(dp[i][j]+1,dp[i][j+1]);
            }
        
        for(i=grid.length-1;i>=0;i--)
            for(j=grid[0].length-1;j>=0;j--)
            {
                if(i>=1)
                    dp[i-1][j]=Math.min(dp[i-1][j],dp[i][j]+1);
                if(j>=1)
                    dp[i][j-1]=Math.min(dp[i][j]+1,dp[i][j-1]);
            }

        for(i=0;i<grid.length;i++)
            for(j=0;j<grid[0].length;j++)
                res=Math.max(res,dp[i][j]);
        //如果返回值是0代表所有格子都被陆地占据，此时依题意应当返回-1
        //如果返回值是400标明所有格子都是海洋，也要返回-1
        if(res==0)
            return -1;
        else if(res==400)
            return -1;
        return res;
    }
}
```