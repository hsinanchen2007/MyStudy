题目描述中提到

```
被除数和除数均为 32 位有符号整数。
除数不为 0。
假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−231,  231 − 1]。本题中，如果除法结果溢出，则返回 231 − 1。
```

因此像使用long、unsigned的均是偷懒做法。这种偷懒是为了避免边界检查的繁琐。
## 本题考点：
* 32位整型的边界检查
* 无乘除mod运算的除法运算

## 解题思路

首先想到的思路就是将`dividend`连续减`divisor`直到`dividend`小于0为止。但是有几个细节问题要考虑。

1. `dividend`和 `divisor`是有符号整数，所以必须要将两者转化为同符号，再进行连续减。
2. 效率问题，`dividend`=0x7FFFFFFF(max_int)，`divisor`=1时会超时。

解决第二个问题可以使用指数逼近的方式(这是核心解决方案，参考其他答案，非常详细了)
针对第一个问题，则有两种解决方式，转化为正数和转化为负数。

32位整形的取值范围是[0x80000000,0x7FFFFFFF] = [-2147483648‬,21474836487]
可以看到最小值和最大值的绝对值不相同，这就使得越界问题变得十分复杂。

越界可能存在的地方：
1. 如果均取绝对值使得符号同化，则当`dividend`=-2147483648‬时，取其绝对值就会越界。
2. 在指数逼近的过程中，逼近结果可能会越界。


对两个问题的解决
1. 将符号同化为负号，利用两个符号进行减
2. 越界判断。

```
int Medium::divide(int dividend, int divisor)
{
	int Max_int = 0x7FFFFFFF;
	int Min_int = 0x80000000;
	// 特殊值处理 0x80000000 / -1
	if (divisor == -1 && dividend == Min_int) return Max_int; 
	// 符号同化
	int flag1 = -1;
	int flag2 = -1;
	if (dividend >= 0)
	{
		flag1 = 1;
		dividend = 0 - dividend;
	}
	if (divisor >= 0)
	{
		flag2 = 1;
		divisor = 0 - divisor;
	}
	// 结果符号
	int flag = 1;
	if (flag1 != flag2) flag = -1;
	// 特殊值处理 -2 / -4 
	if (dividend > divisor) return 0;

	int num = 0;
	int count = 0;
	while (dividend < 0)
	{
		int divisor_pow_current = divisor;
		int divisor_pow_last = 0;
		int result = -1;
		while (true)
		{
			divisor_pow_last = divisor_pow_current;
			// 越界处理 防止 divisor_pow_current += divisor_pow_current 越界
			if (Min_int - divisor_pow_current > divisor_pow_current) break;
			divisor_pow_current += divisor_pow_current;
			if (divisor_pow_current < dividend ) break;
			result += result; 
		}
		dividend -= divisor_pow_last;
		num += result;
	}
	if (dividend != 0) num++;
		
	if (flag < 0) return num;
	else return 0 - num;
}
```

c 超过100%
c++ 超过78%…………
