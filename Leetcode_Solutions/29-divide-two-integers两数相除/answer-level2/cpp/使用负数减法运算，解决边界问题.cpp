边界问题：
1. dividend = INT_MIN, 执行abs(dividend)转换为正整数时溢出；
2. divisor = INT_MIN， 执行abs(divisor)转换时溢出；
3. 当dividend = INT_MIN， divisor = -1时结果res溢出;
为了避免过多的讨论边界问题，将除数和被除数都转换为负数，结果res也用负数计算,
采用的[@powcai](/u/powcai)“倍增除数减法“。

```
class Solution {
public:
	int divide(int dividend, int divisor) {
		int flag = 1;
		if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)) // 查看除数和被除数是否异号
			flag = -1;
		int res = 0;
		if (dividend > 0) dividend = 0 - dividend;
		if (divisor > 0) divisor = 0 - divisor;

		while (dividend <= divisor)
		{
			int temp = divisor, i = -1;
			while (dividend <= temp)
			{
				dividend -= temp;
				res += i;
				if (INT_MIN - temp <= temp) // 检查下一次迭代是否溢出
				{
					i += i;
					temp += temp;
				}
				else                        // 溢出则跳出
					break;
			}
		}
		if (flag == -1) return res;
		if (flag == 1 && res > INT_MIN) return 0 - res;
		return INT_MAX;
	}
};
```


