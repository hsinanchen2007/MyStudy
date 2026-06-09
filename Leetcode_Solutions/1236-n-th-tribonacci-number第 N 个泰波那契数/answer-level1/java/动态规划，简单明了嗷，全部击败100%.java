```
class Solution {
public:
    int tribonacci(int n) {
        int a[10000];
        a[0]=0;
        a[1]=1;
        a[2]=1;
        for(int i=3;i<=n;i++){
            a[i] = a[i-1]+a[i-2]+a[i-3];
        }
        return a[n];
    }
};
```

```
class Solution {
    public int tribonacci(int n) {
        
        if(n==0)
            return 0;
        if(n<=2)
            return 1;
        int[] dp=new int[n+1];
        dp[0]=0;
        dp[1]=1;
        dp[2]=1;
        for(int i=3;i<=n;i++){
            dp[i] = dp[i-1]+dp[i-2]+dp[i-3];
        }
        return dp[n];
    }
}
```

