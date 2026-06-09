dp(i,j) 表示从i开始的子数组 A[i~n]，先取者第一次取j（j=1,2,3）堆能得到的最大分数, 
sum表石子数组A[i~n]的总分数;
dp(i,j)= sum-Math.max(dp(i+1,1), dp(i+1,2),dp(i+1,3));

```java
    public String stoneGameIII(int[] stoneValue) {
        int n=stoneValue.length;
        int[][] dp=new int[n][3];
        int sum=0;
        for(int i=n-1; i>=0; i--){
            sum+=stoneValue[i];
            for (int j = 0; j < 3; j++) {
                dp[i][j]= i+j+1>=n?sum:(sum- Math.max(dp[i+j+1][0], Math.max(dp[i+j+1][1],dp[i+j+1][2])));
            }
        }
//        PrintUtils.print2DIntArray(dp);
        int max= Math.max(dp[0][0],Math.max(dp[0][1],dp[0][2]));
        return max>sum-max?"Alice": (max<sum-max?"Bob":"TIE");
    }
```
