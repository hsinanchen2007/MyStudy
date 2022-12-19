首先，记录下ret是否为负；

当dividend或divisor是INT_MIN的时候，不能divisor = -divisor，因此首先判断divisor是否为INT_MIN，然后把divisor和dividend转换成同号；
接下来找到最高位a，用dividend减去pow(2, a) * 3，接下来去找b...直到dividend小于divisor；
函数返回pow(2, a) + pow(2, b) + ...，当然还要注意边界条件；

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0) return pow(2, 31) - 1;
        long aux = 1;
        long ret = 0;
        bool negative = false;
        if ((dividend < 0) ^ (divisor < 0)) {
            negative = true;
            if (divisor == INT_MIN) return 0;
            divisor = -divisor;
        }

        while (dividend > 0 && dividend >= aux * divisor) aux <<= 1;
        while (dividend < 0 && dividend <= aux * divisor) aux <<= 1;
        aux >>= 1;
        while ((dividend > 0 && dividend >= divisor) || (dividend < 0 && dividend <= divisor)) {
            if ((dividend > 0 && dividend >= aux * divisor) || (dividend < 0 && dividend <= aux * divisor)) {
                dividend -= aux * divisor;
                ret += aux;
            }
            aux >>= 1;
        }

        ret = negative ? -ret : ret;
        if (ret > INT_MAX || ret < INT_MIN) return pow(2, 31) - 1;
        return ret;
    }
};