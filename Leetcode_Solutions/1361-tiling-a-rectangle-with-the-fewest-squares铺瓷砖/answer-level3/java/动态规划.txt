我们定义dp[i][j]表示组成i*j大小的矩形所用最小正方形的个数。
我们考虑如何将问题化为规模更小的问题，其实就是以下三种情况：
1.竖直切割，将矩形分成左右两块。
2.水平切割，将矩形分成上下两块。
3.中间挖走了一块，导致需要将剩下的矩形分成4块，共5块。

相信大家会有疑问为什么情况3这里并没有枚举中间挖走的呢一块的大小，其实我觉得应该是需要枚举中间块的大小的，但是因为这题里的n和m只有13，导致中间并不会出现超过1大小的块吧。
```
class Solution {
    public int tilingRectangle(int n, int m) {
        int[][] dp=new int[15][15];
        
        for(int i=1;i<=n;i++)
        	for(int j=1;j<=m;j++) {
        		dp[i][j]=i==j?1:i*j;
        		for(int p=1;p<i;p++)
        			dp[i][j]=Math.min(dp[i][j], dp[p][j]+dp[i-p][j]);
        		for(int p=1;p<j;p++)
        			dp[i][j]=Math.min(dp[i][j], dp[i][p]+dp[i][j-p]);
        		for(int x=2;x<i;x++)
        			for(int y=2;y<j;y++)
        				dp[i][j]=Math.min(dp[i][j], dp[x-1][y]+dp[x][j-y]+dp[i-x+1][y-1]+dp[i-x][j-y+1]+1);
        	}
        return dp[n][m];
    }
}
```
