`dp[i][j]`代表`i`枚色子和为`j`的概率
递推公式很容易想到 `dp[i][j]= 1/6(dp[i-1][j-1]+dp[i-1][j-2]+dp[i-1][j-3]...dp[i-1][j-6])` 
然后我们枚举各个状态就ok了
```
public double[] twoSum(int n) {
    //dp[i][j]代表i枚色子和为j的概率
    double[][] dp=new double[n+1][6*n+1];
    double probability=1.0/6.0;
    //base初始化
    for(int i=1;i<=6;i++) dp[1][i]=probability;
    for(int i=2;i<=n;i++){ //枚举色子
        for(int j=i;j<=i*6;j++){ //枚举点数
            for(int k=1;k<=j && k<=6;k++){ //枚举当前色子的点数
                dp[i][j]+=(probability*dp[i-1][j-k]);
            }
        }
    }
    double[] res=new double[5*n+1];//
    System.arraycopy(dp[n],n,res,0,res.length);
    return res;
}
```
