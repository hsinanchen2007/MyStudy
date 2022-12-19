### 解题思路

P 数组是字符串以P结尾
L 数组是字符串以L结尾
*P[i] = P[i - 1] + L[i - 1]*
*L[i] = P[i - 1] + P[i - 2]*

最后一个for循环是为了插入A
### 代码

```java
class Solution {
    public int checkRecord(int n) {
        int mod = 1000000007;
        long[] P = new long[n + 1];
        long[] L = new long[n + 1];
        P[1] = 1;
        L[1] = 1;
        P[0] = 1;
        for (int i = 2; i <= n; i ++) {
            P[i] = P[i - 1] + L[i - 1];
            P[i] %= mod;
            L[i] = P[i - 1] + P[i - 2];
            L[i] %= mod;
        }
        long res = L[n] + P[n];
        res %= mod;
        // 插入A
        for (int i = 0; i < n; i ++) {
            long A = ((L[i] + P[i]) % mod * (L[n - i - 1] + P[n - i - 1]) % mod ) % mod; 
            res = (res + A) % mod;
        }
        return (int)res;
    }
}
```