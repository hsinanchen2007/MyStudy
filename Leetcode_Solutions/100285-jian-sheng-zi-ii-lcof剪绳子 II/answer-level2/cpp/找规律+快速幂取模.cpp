### 解题思路
规律：
参考链接https://www.cnblogs.com/yinbiao/p/11598321.html
长度小于4的都可以直接写出来，长度大于等于4的，怎样都不能分割出1，令x=n%3, y=n/3：
4: 2x2, x=1, y=1
5: 2x3, x=2, y=1
6: 3x3, x=0, y=3
7: 2x2x3, x=1, y=2
8: 2x3x3, x=2, y=2
9: 3x3x3, x=0, y=3
10: 2x2x3x3, x=1, y=3
11: 2x3x3x3, x=2, y=3
快速幂取模：
$a^b\%p=((a^{b/2}\%p)*(a^{b/2}\%p))\%p$，$a$为偶数
$a^b\%p=((a^{b/2}\%p)*(a^{b/2}\%p)*(a\%p))\%p$，$a$为奇数

### 代码

```cpp
class Solution {
public:
    long long fastPow(int a, int b)
    {
        //快速幂取模
        //a：底数
        //b：指数
        if(b == 0)return 1;
        if(b == 1)return a;
        long long temp = fastPow(a, b/2)%1000000007;
        long long res = (temp*temp)%(1000000007);
        if(b % 2 == 1)  //指数为奇数
            return res*a;
        return res;
    }
    int cuttingRope(int n) {
        if(n == 1)return 0;
        if(n == 2)return 1;
        if(n == 3)return 2;
        int x = n%3, y = n/3;
        if(x == 0)
        {
            //可以整除
            return fastPow(3, y)%(1000000007);
        }
        if(x == 1)
        {
            return ((2*2)*fastPow(3, y-1))%(1000000007);
        }
        if(x == 2)
        {
            return (fastPow(2, x-1)*fastPow(3, y))%(1000000007);
        }
        return 0;
    }
};
```