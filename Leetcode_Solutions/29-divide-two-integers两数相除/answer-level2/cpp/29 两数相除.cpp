**除法**就是**被除数**减去**除数**，直到**被除数**小于**0**结束

但是一个一个减太慢，如果能将**除数乘以一个n倍数**之后，**被除数**还**大于等于**这个**除数**，则**减去**这个**扩大n倍的除数**。
然后**除数**再扩大**n/2倍**，被除数再去减这个扩大n/2的除数。

由于是int类型，且最高位为符号位，则n最大应该为2^31;

```
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0 || (dividend == INT_MIN && divisor == -1)) return INT_MAX;
        if(divisor == 1) return dividend;
        if(divisor == -1) return -dividend;
        
        long m = abs(long(dividend));
        long n = abs(long(divisor));
        
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
        int res = 0; 
        
        int i = 31;
        while(i >= 0){
            if(m>>i >= n){
                m -= (n<<i);
                res += (1<<i);
            }
            i--;
        }
        res = sign > 0 ? res : -res;
        if(res > INT_MAX)
            res = INT_MAX;
        
        return res;
    }
};
```
