递推公式： f[n] = (n-1)*(f[n-1] + f[n-2])

```
class Solution {
public:
    int findDerangement(int n) {
        long long res = 1;
        int mod = 1000000007;
        if(n == 1){
            return 0;
        }else if(n == 2){
            return 1;
        }
        
        long long first = 0;
        long long second = 1;
        
        /*f[n] = (n-1)*(f[n-1] + f[n-2])*/
        for(int i = 3;i <= n; ++i){
            res = (i-1)*(first + second)%mod;
            first = second;
            second = res;
        }
        
        return res;
    }
};
```