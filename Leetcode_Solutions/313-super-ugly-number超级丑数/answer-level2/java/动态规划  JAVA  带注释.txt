```
class Solution {
    public int nthSuperUglyNumber(int n, int[] primes) {
        int []dp=new int[n]; // dp[i]表示第i+1个超级丑数
        int []index=new int[primes.length]; // 指针数组
        dp[0]=1;
        
       for(int i=1;i<n;i++){
            dp[i]=Integer.MAX_VALUE;
            for(int j=0;j<index.length;j++){ // 找最小值并赋值给dp[i]
                dp[i]=Math.min(dp[i],primes[j]*dp[index[j]]);
            }
            
            for(int j=0;j<index.length;j++){ // 更新指针
                if(primes[j]*dp[index[j]]==dp[i])
                    index[j]++;
            }
        }
        
        return dp[n-1];
        
    }
}
```
