参考评论区题解，实现C++版的负数左移方案。题目限定环境只能存储 32 位有符号整数。这里就没用long。

```
class Solution {
public:
    // 负数左移
    int negtiveLeftShift(int negtiveNum, int count) {
        int num = -negtiveNum;
        num <<= count;
        return -num;
    }
    
    int divide(int dividend, int divisor) {
        bool sign = (dividend > 0) ^ (divisor > 0);
        int result = 0;
        if (dividend > 0) {
            dividend = -dividend;
        }

        if (divisor > 0) {
            divisor = -divisor;
        }

        while (dividend <= divisor) {
            int tempResult = -1;
            int tempDivisor = divisor;
            while (tempDivisor > ( -(1 << 30) ) 
                   && dividend <= negtiveLeftShift(tempDivisor, 1)) {
                tempResult = negtiveLeftShift(tempResult, 1);
                tempDivisor = negtiveLeftShift(tempDivisor, 1);
            }

            result += tempResult;
            dividend -= tempDivisor;
        }

        if (!sign) {
            if (result <= INT_MIN) {
                return INT_MAX;
            }

            result = -result;
        }
        
        return result;
    }
};
```
