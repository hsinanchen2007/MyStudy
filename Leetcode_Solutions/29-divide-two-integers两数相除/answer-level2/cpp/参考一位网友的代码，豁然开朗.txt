### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution 
{
public:
    int divide(int dividend, int divisor)
    {
        //特殊处理
        if (divisor == -1) 
        {
            if(dividend == INT_MIN)
                return INT_MAX; 
            else
                return 0 - dividend;
        }
        if(dividend == 0)
            return 0;
        if(divisor == 1)
            return dividend;

        //转为负数
        int sign = (dividend > 0) ^ (divisor > 0) ? -1 : 1;
        dividend = dividend > 0 ? 0 - dividend : dividend;
        divisor = divisor > 0 ? 0 - divisor : divisor;

        //如果被除数不够除就直接退出
        if (dividend > divisor)
            return 0;

        int result = 0;
        while (dividend < 0)
        {
            //如果被除数不够除就直接退出
            if(dividend > divisor)
                break;

            //开始计算商
            int divisor_pow_current = divisor;
            int count = -1;
            while (true)
            {
                //防止除数翻倍后越界
                if (INT_MIN - divisor_pow_current > divisor_pow_current) 
                    break;

                //防止除数翻倍后大于被除数
                if (divisor_pow_current + divisor_pow_current < dividend) 
                    break;
                
                count += count; 
                //记得除数翻倍
                divisor_pow_current += divisor_pow_current;
            }
            dividend -= divisor_pow_current;
            result += count;
        }
        return sign == 1 ? 0 - result : result; 
    }
};
```