```
class Solution {
    public int countNumbersWithUniqueDigits(int n) {
        //dp[0]=1; dp[1]=10;  dp[2]=9X9+dp[1]=91; dp[3]=9x9x8+dp[2]
        //第二位可以选0
        int[] dp=new int[n+3];
        dp[0]=1;
        dp[1]=10; dp[2]=91;
        if(n<=2) return dp[n];
        for(int i=3;i<=n;i++){
            dp[i]=9*res(9,i-1)+dp[i-1];
        }
        return dp[n];
    }
    public int res(int n,int i){
        int sum=1;
       while(i!=0){
          sum*=n;
          n-=1;
          i--;
       }
       return sum;
    }
}
```
