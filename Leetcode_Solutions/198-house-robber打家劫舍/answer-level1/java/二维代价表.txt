```
public int rob(int[] nums) {

        if(nums==null || nums.length ==0){
            return 0;
        }
        int n = nums.length;
        int[][] dp = new int[n][n];
        //初始化1家 和 2家的情况
        for(int i=0;i<n;i++){
            dp[i][i] = nums[i];
            if(i<n-1){
                dp[i][i+1] = Math.max(nums[i], nums[i+1]);
            }
        }


        //计算任意2家之间的最大收益
        for(int step = 2; step <= n-1;step++){
            for(int i=0; i<n-2; i++){
                int j = i+step;
                if(j>n-1){
                    break;
                }
                //3种情况：选i,从i+2开始
                int method1 = nums[i] + dp[i+2][j];
                //选j j-2之前
                int method2 = nums[j] + dp[i][j-2];
                //i, j都不选
                int method3 = dp[i+1][j-1];

                dp[i][j] = Math.max(method1,Math.max(method2,method3));
            }

        }

        //返回第一家到第n家的收益
        return dp[0][n-1];



        
    }
```
