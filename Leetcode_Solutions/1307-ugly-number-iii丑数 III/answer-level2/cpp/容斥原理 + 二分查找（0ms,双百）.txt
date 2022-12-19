## 容斥原理 + 二分查找

找第n个 可以被 a 或 b 或 c 整除的 正整数，我们想到**容斥原理**

但是题目的数据范围是10^9，需要O(logn)的操作，想到二分查找

那能否用二分查找呢？

二分的状态 f(x) 表示[0,x]中有多少个丑数，二分查找求`f[x] == n`的x的值

二分查找的条件：

- 单调性：随着数字增大，n是逐渐增大的，满足
- 两段性：前半段数量小于n,后半段大于等于n,满足

## 代码实现

```cpp
class Solution {
public:
    typedef long long LL;

    int a, b, c;
    vector<int> st; // 得到不含互相整除的所有数的集合

    int nthUglyNumber(int n, int a, int b, int c) {
        if (a == 1|| b == 1|| c== 1) return n;
        bool exist[3];
        memset(exist, true, sizeof(exist));
        if ((exist[1] && a % b == 0 )|| (exist[2] &&a % c == 0 )) exist[0] = false;
        if ((exist[0] &&b % a == 0) || (exist[2] &&b % c == 0)) exist[1] = false;
        if ((exist[1] && c % b == 0) || (exist[0] &&c %a == 0)) exist[2] = false;
        if (exist[0])st.push_back(a);
        if (exist[1])st.push_back(b);
        if (exist[2])st.push_back(c);
        LL x = 2 * pow(10, 9);
        return divide(x, n);
    }

    LL divide(LL x, int n){
        LL l = 1, r = x;
        while (l < r){
            LL mid = l + r >> 1;
            if (getCnt(mid)>= n) r = mid ;
            else l = mid +1;
        }
        return l;
    }

    LL getCnt(LL n) { // 容斥原理 + 二进制
        int m = st.size(); 
        int ans = 0;
        for (int k = 1; k < 1 << m; k++){
            LL cnt = 0, t = 1;
            for (int j = 0; j < m; j++){ // 第j位
                if (k & 1 << j) {
                    cnt ++;
                    t = t * st[j] / gcd(t, st[j]); // 求集合的最小公倍数
                    if (t > n){
                        t = -1;
                        break;
                    }
                }
            }
            if (t != -1) {
                if (cnt % 2) ans += n / t;
                else ans -= n/t;
            }
        }
        return ans;
    }

    int gcd(int a , int b){
        return b ? gcd(b, a%b): a;
    }
};
```

![0ms,双百](https://pic.leetcode-cn.com/6f5ed014c62103c000df8f4284711f9c192838ad8c76a35825747088c213d2be.png)
