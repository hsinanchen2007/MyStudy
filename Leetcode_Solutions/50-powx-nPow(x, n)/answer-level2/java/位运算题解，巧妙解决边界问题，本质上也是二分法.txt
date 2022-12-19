```
class Solution {
    public double myPow(double x, int n) {
        if (0 == x || x == 1) return 1;
        // 负数的最小值，取负无法得到正值
        // 例如八位二进制最小值10000000，十进制表示-128，最高位是符号位，等于-0，
        if (n < 0) return 1 / (x * myPow(x, -(n + 1)));
     
        double pow = 1;
        while (n > 0) {
            if ((n & 1) > 0) { // 相当于if(n % 2 == 1)
                pow *= x;
            }
            x *= x;  // 快速幂算法的核心在于不断对x做平方运算
            n >>= 1;
        }
        return pow;
    }
}
```
