
```cpp
class Solution {
public:
    //二分法，不断将指数减半
    double basicPow(double x, long n){
        if(n == 0)  return 1.0; // 顶
        double half = basicPow(x, n / 2);
        if(n % 2 == 0){ //根据奇偶性分
            return half * half;
        }
        else{
            return half * half * x;
        }
    }
    double myPow(double x, int n) {
        long N = n;
        if(N == 0)  return 1.0;
        if(N < 0){ //处理指数为负数的情况
            x = 1 / x;
            N = - N;
        }
        return basicPow(x, N);
    }
};
```
