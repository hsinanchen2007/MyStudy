
首先，我们要写出该题解法的递归版本，然后改成动态规划。这道题最关键的就是能够想到用一个boolean值表示前两个颜色是否相同。

递归版本：
变量i：走到第i个位置
flag：之前两个颜色是否相同，相同为true，否则为false
base case：当i走到n的时候停止

有一点要注意的就是i=1的时候，flag只可能为false，单独列出

递归版本没有做数据清洗，写递归的目的主要是要得到转移方程

```java

 class Solution {
     public int numWays(int n, int k) {
         return process(n,k,1,false);
     }
    
     public int process(int n,int k,int i,boolean flag){
        
         if(i==n && flag==true){
             return k-1;
         }
         if(i==n && flag==false){
             return k;
         }
         if(i==1){
             return process(n,k,i+1,false)*k;
         }
         return flag==false?process(n,k,i+1,true)+process(n,k,i+1,false)*(k-1):process(n,k,i+1,false)*(k-1);
     }
 }
```

从递归版本可以看出总共有两个变量，当前位置i和前两个位置颜色是否相同的Boolean值flag。将dp数组填好就能得到最终结果了
```java
class Solution{
    
    public int numWays(int n,int k){
        if(n==0||k==0){
            return 0;
        }
        if(n==1){
            return k;
        }
        int[][] dp = new int[n+1][2];
        dp[n][0] = k;
        dp[n][1] = k-1;
        for(int i=n-1;i>1;i--){
            dp[i][0] = dp[i+1][1]+dp[i+1][0]*(k-1);
            dp[i][1] = dp[i+1][0]*(k-1);
        }
        dp[1][0] = dp[2][0]*k;
        dp[1][1] = dp[2][0]*k;
        return dp[1][0];
    }
}
```

