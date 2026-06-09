### 解题思路
组合  快速加避免溢出

### 代码

```cpp
const int MOD = 1e9+7;
class Solution {
private:
    bool prime[100+5];
public:
    void init()
    {
        memset(prime,true,sizeof(prime));
        prime[0]=prime[1]=false;
        for(int i=2;i<=floor(sqrt(100+5)+0.5);i++)
        {
            if(prime[i]) {
                for(int j=i*i;j<102;j+=i)
                    prime[j] = false;
            }
        }
    }
    int multi_mod(int a,int b)
    {
        int ans = 0;
        while(b)
        {
            if(b&1) ans=(ans+a)%MOD;
            a=(a+a)%MOD;
            b>>=1;
        }
        return ans;
    }
    int numPrimeArrangements(int n) {
        if(n<=2) return 1;
        init();
        int is_prime = 0;
        for(int i=1;i<=n;i++)
        {
            if(prime[i]) is_prime++;
        }
        int solve=1;
        for(int i=1;i<=is_prime;i++)
        {
            solve = multi_mod(solve,i);
        }
        for(int i=1;i<=n-is_prime;i++)
        {
            solve = multi_mod(solve,i);
        }
        return solve;
    }
};
```