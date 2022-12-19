```
class Solution {
public:
    bool isPrime(int n)
    {
        if(n<=1) return false;
        for(int i=2;i<n/2+1;i++)
        {
            if(n%i==0) return false;
        }    
        return true;
    }

    int numPrimeArrangements(int n) {
        // 假设1~n中的质数个数为M，合数个数为N，结果为M的全排列乘以N的全排列
        int a = 0, b = 0, MOD = 1000000007;
        long res = 1;
        for(int i=1;i<=n;i++)
        {
            cout<<i<<" : "<<isPrime(i)<<endl;
            if(isPrime(i)) 
                a++;
            else 
                b++;
        }

        while(a>0)
        {
            res = res * a % MOD;
            a--;
        }

        while(b>0)
        {
            res = res * b % MOD;
            b--;
        }

        return res;
    }
};
```