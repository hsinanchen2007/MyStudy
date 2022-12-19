### 解题思路
问题可以理解为dividend包含多少个divisor，这个个数记为quotient。直观想法是：令quotient = 1,2,3,4,...一个个去试，直至逼近dividend，但这样是线性增长，速度太慢。考虑指数增长：令quotient = 1,2,4,8,...一个个去试，当即将要超过dividend时，令增量重回1,2,4,8,...，如此往复，直至逼近dividend。这一过程中要注意防止溢出。

### 解题步骤
* 考虑会导致溢出的特殊情况：dividend = INT_MIN，divisor = -1。
* 考虑简单的特殊情况：divisor = 1或-1，这种情况下没必要一个个去试。
* 记录dividend和divisor的符号，然后将它们都转为负数（若转为正数可能溢出）。
* 比较dividend和divisor，若dividend < divisor（|dividend| > |divisor|），则假定quotient为正，应用指数增长法得到quotient（已经排除了divisor = 1或-1的情况，因此quotient不会溢出）。
* 给quotient加上符号，得到最终结果。

### 代码

```cpp
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == -1) {
            if (dividend == INT_MIN)
                return INT_MAX;
            return -dividend;
        }
        if (divisor == 1)
            return dividend;

        int dividendSign = -1, divisorSign = -1;
        // convert dividend and divisor to negative to avoid overflow
        if (dividend > 0) {
            dividendSign = 1;
            dividend = -dividend;
        }
        if (divisor > 0) {
            divisorSign = 1;
            divisor = -divisor;
        }

        // assume that quotient is positive
        int quotient;
        if (dividend > divisor)
            quotient = 0;
        else if (dividend == divisor)
            quotient = 1;
        else {
            quotient = 1;
            int divisorTotal = divisor, divisorAdd = divisor;
            int quotientAdd = 1;
            while (true) {
                int borderLeft = INT_MIN - divisorTotal;
                // if add divisorAdd will not overflow
                if (borderLeft <= divisorAdd) {
                    // try to add divisorAdd
                    int divisorTotalTemp = divisorTotal + divisorAdd;
                    // if add divisorAdd will not exceed dividend
                    if (divisorTotalTemp > dividend) {
                        divisorTotal = divisorTotalTemp;
                        quotient += quotientAdd;
                        divisorAdd += divisorAdd;
                        quotientAdd += quotientAdd;
                        continue;
                    } else if (divisorTotalTemp == dividend) {
                        quotient += quotientAdd;
                        break;
                    }
                }
                // if add divisor will not overflow
                if (borderLeft <= divisor) {
                    // try to add divisor
                    int divisorTotalTemp = divisorTotal + divisor;
                    // if add divisor will not exceed dividend
                    if (divisorTotalTemp > dividend) {
                        divisorTotal = divisorTotalTemp;
                        quotient += 1;
                        divisorAdd = divisor;
                        quotientAdd = 1;
                        continue;
                    } else if (divisorTotalTemp == dividend) {
                        quotient += 1;
                        break;
                    }
                }
                break;
            }
        }

        if (dividendSign == divisorSign)
            return quotient;
        else
            return -quotient;
    }
};
```