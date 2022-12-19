### 解题思路
这里面用到了n和-n在内存中是按位反后+1的知识点，但由于力扣在运行时禁止INT_MAX+1=INT_MIN这样的逻辑，所以有一些代码看上去有些重复

### 代码

```cpp
class Solution {
public:
    int divide(int dividend, int divisor) {
		if (0 == divisor)
		{
			return INT_MAX;
		}
		else if (1 == divisor)
		{
			return dividend;
		}
		else if (-1 == divisor)
		{
			return dividend == INT_MIN ? INT_MAX : -dividend;
		}
		
		if (0 == dividend)
		{
			return 0;
		}
		if (dividend == divisor)
		{
			return 1;
		}

		bool resPositive = ((dividend ^ divisor) | INT_MAX) == INT_MAX;

		if (dividend > 0)
		{
			dividend = -dividend;
		}

		if (divisor > 0)
		{
			divisor = -divisor;
		}

		if (dividend > divisor)
		{
			return 0;
		}

		int resTmp = 1, edge = INT_MIN >> 1;
		while (dividend < divisor && divisor >= edge)
		{
			divisor = (~(~divisor << 1)) - 1;
			resTmp <<= 1;
		}

		int res = 0;

		while (resTmp > 0)
		{
			if (dividend == divisor)
			{
				res += resTmp;
				return resPositive ? res : -res;
			}
			else if (dividend > divisor)
			{
				divisor >>= 1;
				resTmp >>= 1;
			}
			else
			{
				res += resTmp;
				dividend -= divisor;
				divisor >>= 1;
				resTmp >>= 1;
			}
		}

		return resPositive ? res : -res;
    }
};
```