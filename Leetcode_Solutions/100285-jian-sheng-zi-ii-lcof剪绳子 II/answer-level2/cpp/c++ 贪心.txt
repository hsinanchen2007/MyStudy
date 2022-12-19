# 思路

对于n<=3 显然是n-1
n>3开始, 找找规律：考虑到一个6拆成3×3 要大于 2×2×2, 一个4拆成1×3 要小于2×2, 一个5拆成2×3非常合理
 **因此想到绳子长度对3取模分情况**

1. 如果整除3, 那么全是3
2. 如果余1, 那么是两个2, 剩下全是3
3. 如果余2, 那么是一个2, 剩下全是3
4. 特别注意取模就可以

```
class Solution {
private:
    const int MOD = 1000000007;
    long long myPow3(int n){
        long long ret = 1;
        for (int i = 0; i < n; ++i){
            ret *=3;
            ret %=MOD;
        }
        return ret;
    }
public:
    int cuttingRope(int n) {
        if (n <= 3) return n - 1;
        else
        {
            if (n % 3 == 0) return (int)myPow3(n / 3);
            else if (n % 3 == 1) {
                long long pre = myPow3(n / 3 - 1);
                int ret = (int)((pre * 4) % MOD);
                return ret;
            }
            else{
                long long pre = myPow3(n / 3);
                int ret = (int)((pre * 2) % MOD);
                return ret;
            }
        }
    }
};
```