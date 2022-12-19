假设第n道菜的顺序是j   第n-1道菜的最大值的顺序是j-1

先排序,
第2个数,第0-1的所有顺序为1,2 1为第一个菜 即前面没菜  2为第二个菜 即前面做了一个菜
...
第n个数,遍历0-n-1,  顺序为1 到n+1,
```
 public int maxSatisfaction(int[] satisfaction) {
       int n = satisfaction.length;
        if(n==0)
            return 0;
        Arrays.sort(satisfaction);
        int[][] dp =new int[n][n+1];
        int max =Integer.MIN_VALUE;
        for(int i=0;i<n;i++){
            for(int j=1;j<=n;j++){
                dp[i][j]=Integer.MIN_VALUE;
            }
            dp[i][1] = satisfaction[i];
            max = Math.max(max,satisfaction[i]);
        }
       for(int i=1;i<n;i++){
           for(int m=0;m<i;m++){
               for(int j=2;j<=i+1;j++){
                   if(dp[m][j-1]!=Integer.MIN_VALUE){
                       dp[i][j]=Math.max(dp[i][j],satisfaction[i]*j+dp[m][j-1]);
                       max =Math.max(max,dp[i][j]);
                   }
               }
           }
       }
       max = Math.max(max,0);
       return max;
    }
}
```
