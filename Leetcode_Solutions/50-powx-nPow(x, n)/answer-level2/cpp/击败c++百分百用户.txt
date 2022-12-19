
![批注 2019-07-19 215934.png](https://pic.leetcode-cn.com/780e370ddf5aa709b81a9adf68f616a1b9af67472563206a3d4d1fd767e34bdf-%E6%89%B9%E6%B3%A8%202019-07-19%20215934.png)


先介绍快速幂：


众所周知，如果我们要求a的n次方，最朴素的想法一定是把它们乘起来，这样的复杂度是O(n),显然太差了。


然后我们想到一种优化，如果我们能求得 2的k次方=n的话，我们只需要将a的平方相乘k次，这样的复杂度是O(log2n)，但是我们很难找到这样的k。


于是我们将这一想法再一次优化，我们只要能找到 2的k1次方+2的k2次方+...=n就好了，这样的复杂度还是O(log2n)


这一想法可以通过数的二进制位运算轻易解决，比如9的二进制是1001，也就是从右往左数第i位，我们的答案就乘上a的2的i次方


于是就有了一下算法


```c++ []
class Solution {
public:
    
    double qpow(double a, long long b){
        double res = 1;
        while(b){
            if(b&1) res = res*a;
            b >>= 1;
            a *= a;
        }
        return res;
    }
    
    
    double myPow(double x, long long n) {
        if(n == 0) return 1;
        if(n > 0) return qpow(x,n);
        if(n < 0) return 1/qpow(x,-n);
        return 1.0;
    }
};
```
