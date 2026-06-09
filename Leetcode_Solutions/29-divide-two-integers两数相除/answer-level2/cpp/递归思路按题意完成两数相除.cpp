### 解题思路
此解法未使用乘除mod，也未使用long这种讨巧的方式避开溢出，仅采用int进行，主要注意点有
1. 避免溢出和对于被除数和除数一些特殊判定以加快运算速度和避免出错
2. 采用被除数减除数来做到除的效果
3. 采用除数自增翻倍的思想加快减法的速度
4. 考虑到符号和可能的溢出，这里将除数和被除数转换为负数进行运算，同时传递运算结果的符号

### 代码

```cpp
class Solution {
public:
	int subDivide(int dividend, int divisor, bool minus)
	{
		int i = 0, times = 1;
		int originDivisor = divisor;
		while (dividend <= divisor && dividend <= 0)
		{
			dividend -= divisor;
 			i += times;           
            if (dividend >= divisor)
            {
                break;
            }
			divisor += divisor;
			times += times;
		}

		if (dividend > originDivisor)
		{
			if (minus)
				return -i;
			else
				return i;
		}
		else
		{
			if (minus)
				return -i + subDivide(dividend, originDivisor, minus);
			else
				return i + subDivide(dividend, originDivisor, minus);
		}
	}

	int divide(int dividend, int divisor) {
		int i = 0, times = 1, left = 0;
		bool minus = false;
		
		if (dividend == INT_MIN)
		{
			if (divisor == -1)
				return INT_MAX;
			else if (divisor == 1)
				return INT_MIN;
			else if (divisor == INT_MIN)
				return 1;
		}
		else if (divisor == INT_MIN)
			return 0;
        else if (divisor == 1)
            return dividend;
        else if (divisor == -1)
            return -dividend;

		if (dividend < 0 && divisor > 0)
		{
			minus = true;
			divisor = -divisor;
		}
		else if (dividend > 0 && divisor < 0)
		{
			minus = true;
			dividend = -dividend;
		}
        else if (dividend > 0 && divisor > 0)
        {
 			divisor = -divisor;
			dividend = -dividend;                        
        }

		return subDivide(dividend, divisor, minus);
	}
};
```