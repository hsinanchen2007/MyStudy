```c++
class Solution {
public:
    double myPow(double x, int n) {
        // n是整数...
        // 最简单的思路是利用二分的思想 比如 x = 3, n = 4 ==> (3^2)^2
        // 要考虑 n是 奇数 偶数 ,偶数可以被二整除
        // 奇数的话由于是整除 2 会损失一次乘以x的机会,所以要补起来
        // 如果是负数, 比如 x = 2 n = -5 ==> x = 1/2 n = 5
        if(n == 0)
            return 1;
        if(n == 1)
            return x;
        if( n == -1)
            return 1/x;
        double res = myPow(x, n/2);      //递归求解 (x)^(n/2)
        res *= res;                    
        if(n < 0)
            x = 1/x;
        if(n % 2)
            res *= x;
        return res;
    }
};
``