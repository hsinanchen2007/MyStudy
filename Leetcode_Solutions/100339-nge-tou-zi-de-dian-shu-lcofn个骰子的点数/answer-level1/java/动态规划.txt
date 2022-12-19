```
class Solution {
    public double[] twoSum(int n) {
        //dp[i][j]，i表示色子，j代表总点数
        double[][] dp=new double[n+1][6*n+1];
        //初始化
        for(int j=1;j<=6;j++){
            dp[1][j]=1;
        }
        //投了几个色子（第几轮）
        for(int i=2;i<=n;i++){
            //这一轮的 色子总大小 的范围
            for(int j=i;j<=6*i;j++){
                //色子的点数
                for(int k=1;k<=6;k++){
                    //第i个色子总数肯定比i-1个色子总数大（j>k）
                    //进行dp[i][j]=dp[i-1][j-1]+dp[i-1][j-2]+...+dp[i-1][j-6]
                    //式子怎么来的？
                    //https://leetcode-cn.com/problems/nge-tou-zi-de-dian-shu-lcof/solution/di-gui-huo-zhe-die-dai-du-ke-yi-python-and-javascr/
                    if(j>k) dp[i][j]=dp[i][j]+dp[i-1][j-k];
                }
            }
        }

        double total=Math.pow(6,n);
        //n个色子，最大值为6n，最小值为n，中间间隔大小为5n（6n-n），还包括n本身，+1 -->5n+1
        double[] res=new double[5*n+1];
        //使用 '/' 进行计算，必须保证有一个为
        for(int i=0;i<5*n+1;i++){
            res[i]=((double)dp[n][i+n])/total;
        }
        return res;

    }
}
```
