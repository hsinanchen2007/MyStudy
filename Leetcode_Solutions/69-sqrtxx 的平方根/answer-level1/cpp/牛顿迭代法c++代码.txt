牛顿迭代法的本质是以直代曲不断逼近，已经有题解做了详细分析，本文仅提供c++版本的代码；

```
class Solution {
public:
    int mySqrt(int x) {
        //int ret = sqrt(x);
        if(x == 0 || x == 1) return x;
        //Newton's method
        int ret = x;
        int x0 = x;
        while(1){
            x0 = 0.5*x0 + 0.5*x/x0;
            if(x0*1.0 <= x/x0 && (x0+1)*1.0 > x/(x0+1)){    //注意这里要使用x0 <= x / x0的形式，防止整数溢出
                ret = x0;
                break;
            }
        }
        return ret;
    }
};
```
