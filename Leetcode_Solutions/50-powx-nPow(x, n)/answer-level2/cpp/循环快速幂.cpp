### 解题思路
1、n的处理
1、n == 0
3、n == 1，执行用时少一点
4、右移代替/2

### 代码

```cpp
class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        if(n == 1) return x;
        long long N = n;
        if(N < 0){
            N = - N;
            x = 1 / x;
        }
        double rt = 1;
        double cur = x;
        for(long long i = N; i > 0; i = i>>1){
            if(i % 2 == 1){
                rt = rt * cur;
            }
            cur = cur * cur;
        }
        return rt;
    }
};
```