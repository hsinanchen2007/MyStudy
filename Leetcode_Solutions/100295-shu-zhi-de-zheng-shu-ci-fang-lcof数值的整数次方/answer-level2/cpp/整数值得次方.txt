### 解题思路
此题注意，我想把正负统一，我定义的N不能是int 类型，这样会溢出，当负数转换的时候，但是如果不做转换后面的移位运算可能会有错误，因为正数和负数的补码是不一样的；

### 代码

```cpp
class Solution {
public:
    double myPow(double x, int n) {
        double sum = 1.0;
        long N = n;
        if(n < 0){
            x = 1 / x;
            N = -N;
        }
        while(N){
            if(N&1) sum *= x;
            x *= x;
            N >>= 1;
        }
        return sum;
    }
};
```