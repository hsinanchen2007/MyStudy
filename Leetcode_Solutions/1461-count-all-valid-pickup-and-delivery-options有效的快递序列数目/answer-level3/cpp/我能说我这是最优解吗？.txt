![Annotation 2020-03-25 111127.png](https://pic.leetcode-cn.com/703843059a211c4fbc2f7cb6f00d13c1a0d4a09bd71851464e1b706fba5e81c7-Annotation%202020-03-25%20111127.png)

这题可以把空位插成下一组的p,d
对于第一组来说
_ _ p1 _ _ d1 _ _
p2可以放在:
p2 _ p1 _ _ d1 _ _   此时d2 有3个位置可以放，记作 3
_ _ p1 p2 _ d1 _ _   此时d2 有2个位子可以放，记作 2
_ _ p1 _ _ d1 p2 _   此时d2 有1个位子可以放，记作 1
**观察可得，这是一个等差数列，验证n=3，发现可行，于是O(1)空间即可**
```cpp
typedef long long LL;
const LL MOD=1e9+7;
class Solution {
public:
    LL sum(LL x) {
        return x*(x+1)/2;
    }
    int countOrders(int n) {
        if (n==1) {
            return 1;
        }
        LL pre=1;
        for (LL i=2;i<=n;i++) {
            LL cnt=(i-1)*2+1;
            LL x=sum(cnt)%MOD;
            LL f=x*pre%MOD;
            pre=f%MOD;
        }
        return pre;
    }
};
```