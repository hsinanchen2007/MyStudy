我们发现每一个序列往后加一个字母， 只和前一个字符有关。 利用加法原理， 可以直接推出。

我们用$f(i, char)$来表示前$i$个字符以$char$结尾和合法字符串数量。

则由规则可以得到。
$f(i, 'a') = f(i-1, 'e') + f(i-1, 'i') + f(i-1, 'u')$
其余类推。

注意取模的时候， 因为1e9 + 7 比较大， 5e9会超过int上限， 所以最后一步的时候需要连续取模或者转为long long.

```
class Solution {
public:
    int countVowelPermutation(int n) {
        int a,e,i,o,u;

        if(n == 1)return 5;
        a = e = i = o = u = 1;

        const int mod = 1e9 + 7;

        for(int j = 2; j <= n; j++){
            int aa, ee, ii, oo, uu;

            aa = ((e + i) % mod + u) % mod;
            ee = (a + i) % mod;
            ii = (e + o) % mod;
            oo = i;
            uu = (i + o) % mod;
            
            a = aa, e = ee, i = ii, o = oo, u = uu;
            //printf("%d %d %d %d %d\n",a,e,i,o,u);
        }

        return ((long long) a + e + i + o + u) % mod;
    }
};
```

时间复杂度$O(n)$
空间复杂度$O(1)$
