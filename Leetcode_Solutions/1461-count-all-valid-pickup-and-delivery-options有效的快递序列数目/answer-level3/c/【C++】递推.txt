递推一下和农容易就得到规律了，有一点想斐波那契数列，由于关系全是由乘法组成的，所以可能用来在进行乘法运算的时候取余。

```
const int MOD = 1e9 + 7;
class Solution {
    long f[505];
public:
    int countOrders(int n) {
        f[1] = 1;
        f[2] =6;
        f[3] =90;
        for(int i=4;i<=500;i++) {
            f[i]=(2*i-1)*f[i-1]*i%MOD;
        }
        return f[n];
    }
};
```c