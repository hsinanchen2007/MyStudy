```
 public int minCost(int[][] costs) {
     if(costs==null||costs.length==0||costs[0].length==0)return 0;
        int num=costs.length,ptr=0;
        int[]dp=new int[3],
                pre=new int[3];//dp(j)表示第i排房子第j种颜色的最小费用
                              //pre(j)表示第i-1排房子第j种颜色的最小费用

       //第一排房子
        pre[0]=costs[0][0];
        pre[1]=costs[0][1];
        pre[2]=costs[0][2];
        for (int i = 2; i <=num ; i++) {
                //第i排房子颜色不能与第i-1排重复
                dp[0]=Math.min(costs[i-1][0]+pre[2],costs[i-1][0]+pre[1]);
                dp[1]=Math.min(costs[i-1][1]+pre[2],costs[i-1][1]+pre[0]);
                dp[2]=Math.min(costs[i-1][2]+pre[0],costs[i-1][2]+pre[1]);
            
            for (int s = 0; s <3 ; s++) {
                pre[s]=dp[s];
            }

        }
        return Math.min(pre[0],Math.min(pre[1],pre[2]));
    }
```
