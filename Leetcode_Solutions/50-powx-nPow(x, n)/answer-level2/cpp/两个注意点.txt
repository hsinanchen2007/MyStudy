1. n有可能是INT_MIN，这时候n=-n的话会超出数值范围，因此用long N = n；先转换一下；
2. 单纯暴力超时，用pow(x, n) = pow(x, n / 2) * pow(x, n /2)去递归；

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1.;
        long N = n;
        if (n < 0) {
            x = 1. / x;
            N = -N;
        }
        return fastPow(x, N);
    }
    double fastPow(double x, long n) {
        if (n == 1) return x;
        double half = fastPow(x, n >> 1);
        if (n & 0x01) return half * half * x;
        else return half * half;
    }
};