- dp 时间复杂度$O(n^2)$
```c++
class Solution {
public:
    int integerBreak(int n) {
        vector<int>dp(n+1);
        for(int i=1;i<=n;i++){
            int m = 0;
            for(int j=i>>1;j>=1;j--){
                m = max(m,max(dp[i-j],i-j) * max(dp[j],j));
            }
            dp[i] = m;
        }
        return dp[n];
    }
};
```
- 贪心 时间复杂度O(lg n)
```c++
class Solution {
public:
    int integerBreak(int n) {
        if(n<=3)return n - 1;
        const int mod = 1000000000 + 7;
        long a = n % 3,res=1,three=3;
        n /= 3;
        n--;
        while(n){
            if(n & 1)res = (res * three) % mod;
            three = (three * three) % mod;
            n >>= 1;
        }
        if(!a)return res * 3 % mod;
        else if(a==1)return res * 4 % mod;
        else return res * 6 % mod;
    }
};
```