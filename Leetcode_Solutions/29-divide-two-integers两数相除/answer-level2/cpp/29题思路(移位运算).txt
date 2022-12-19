### 解题思路
m = (a0 * 2^0 + a1 * 2^1 + a2 * 2^2+...+ ak * 2^k) * n, ai = 0或1
若m > n,则计算m最多容纳2^k个n,然后m - 2^k * n,结果res + 2^k
对m余下部分进行一样的计算
### 代码

```cpp
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;//注意这个特殊情况，只有这个情况会溢出
        int sign = (dividend < 0 ^ divisor < 0)?-1:1;//一行代码求出符号
        long res = 0,m = labs(dividend),n = labs(divisor);
        while(m >= n){
            long p = 1,temp = n;
            while(m >= (temp << 1)){//temp<<1这个部分有可能会导致溢出，故需要选择long类型
                temp <<= 1;
                p <<= 1;
            }
            res += p;
            m -= temp;
        }
        return res*sign;
    }
};
```