### 解题思路
除数倍增，被除数=（被除数-除数倍增）
ps：
可将dividend、divisor及result都置为负值，可以不使用long（但leetcode不支持负值左移）
### 代码

```cpp
class Solution {
public:
    int divide(int dividend, int divisor) {
        long long l_dividend = dividend, l_divisor = divisor;
        bool tag = (l_dividend > 0 && l_divisor > 0) || (l_dividend < 0 && l_divisor < 0);
        if(l_divisor < 0) l_divisor = -l_divisor;
        if(l_dividend < 0) l_dividend = -l_dividend;
        long long rt = 0;
        long long tmp_divisor, tmp_result;
        while(l_divisor <= l_dividend){
            tmp_divisor = l_divisor;
            tmp_result = 1;
            while((tmp_divisor << 1) < l_dividend){
                // if((tmp_divisor << 1) > INT_MAX) break;
                tmp_result = tmp_result << 1;
                tmp_divisor = tmp_divisor << 1;
            }
            l_dividend -= tmp_divisor;
            rt += tmp_result;
        }
        if(!tag) rt = -rt;
        if(rt > INT_MAX || rt < INT_MIN) return INT_MAX;
        return rt;
    }
};
```