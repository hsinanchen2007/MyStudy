### 解题思路
用时接近3000ms

### 代码

```cpp
class Solution {
public:
    int divide(int dividend, int divisor) {
        bool is_neg = false;
        long re = 1;
        long _dividend = dividend;
        long _divisor = divisor;
        if (dividend<0 || divisor<0) {
            if (dividend<0 && divisor<0) {
                is_neg = false;
                _dividend = -_dividend;
                _divisor = -_divisor;
            }
            else if (dividend<0) {
                _dividend = -_dividend;
                is_neg = true;                
            }
            else {
                _divisor = -_divisor;
                is_neg = true;
            }
        }
        long __divisor = _divisor;
        while (__divisor < _dividend) {
            if (__divisor << 1 <= _dividend) {
                __divisor += __divisor;
                re += re;
            }
            else {
                __divisor += _divisor;
                re++;
            }
        }
        re = __divisor == _dividend ? re : --re;
        if (re > INT_MAX && !is_neg || -re <INT_MIN) return INT_MAX;
        else return is_neg ? -re : re;
    }
};
```