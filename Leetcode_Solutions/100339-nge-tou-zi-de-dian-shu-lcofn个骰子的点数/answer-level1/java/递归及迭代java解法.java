递归解法：
```java []
class Solution {
    public double[] twoSum(int n) {
        double[] sum=new double[5*n+1];
        int m=n;
        for(int i=0;i<sum.length;i++){
            sum[i]=summa(m,n)/Math.pow(6,n);
            m++;
        }
        return sum;
    }
    public long summa(int m,int n){
        if(m<=0){return 0;}
        if(n==1){return m<=6?1:0;}
        return summa(m-1,n-1)+summa(m-2,n-1)+summa(m-3,n-1)+summa(m-4,n-1)+summa(m-5,n-1)+summa(m-6,n-1);
    }
}
```
递归解法超出时间限制，故使用迭代解法：
```java []
class Solution {
    public double[] twoSum(int n) {
        long[][] dp=new long[n][6*n];
        double[] sum=new double[5*n+1];
        for(int i=0;i<6;i++){
            dp[0][i]=1;
        }
        for(int i=1;i<n;i++){
            for(int j=i;j<=6*(i+1)-1;j++){
                for(int k=1;k<=6;k++){
                    if(j-k>=0){
                        dp[i][j]+=dp[i-1][j-k];
                    }
                }
                //dp[i][j]=dp[i-1][j-1]+dp[i-1][j-2]+dp[i-1][j-3]+dp[i-1][j-4]+dp[i-1][j-5]+dp[i-1][j-6];
            }
        }
        for(int p=0;p<sum.length;p++){
            sum[p]=dp[n-1][p+n-1]/Math.pow(6,n);
        }
        return sum;
    }
}
```
