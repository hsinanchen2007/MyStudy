题目意思很明确，不能用超过32位以上的类型，所以考虑完边界情况后，输入值任何值，除法的结果是不会溢出的。
下面的JavaScript和Java代码在凌晨3点半左右执行均打败99以上，甚至高达99.92%，或许是并发量小的原因吧。

```
function T29(dividend, divisor) {
	//除数为0返回-1，测试用例写的
	if (divisor == 0) return -1;
	//被除数为0返回0
	if (dividend == 0) return 0;
	//除数为1返回被除数
	if (divisor == 1) return dividend;
	//极端用例，负数的最大绝对值大于正数最大绝对值
	if (dividend==-2147483648 && divisor==-1) return 2147483647;
	if (dividend==-2147483648 && divisor==1) return -2147483648;
	//由于-2147483648取反会溢出，所以全部转成负整数
	var x = divisor > 0 ? -divisor : divisor;
	var y = dividend > 0 ? -dividend : dividend;
	//当被除数小于除数时，还可以除
	var ans = 0;
	while (y <= x) {
		var i = 1, xi = x << i;
		//当被除数加上除数的2倍、4倍、8倍还小于0时，继续加x<<i，注意x<<i仍然是负数
		while (xi < 0 && y - xi < 0) {
			i++;
			xi = x << i;
		}
		//由于是指数倍加上除数的倍数的绝对值，把被除数接近到差刚刚小于0的情况
		y -= (x << (i - 1));
		//被除数加上除数i-1的指数倍，商包含1<<(i-1)
        ans += (1 << (i - 1));
	}
	//异或取反，此时ans不存在溢出问题
    if (dividend > 0 ^ divisor > 0) ans = -ans;
    return ans;
}
```

```
public int T29(int dividend, int divisor) {
	//除数为0返回-1，测试用例写的
	if (divisor == 0) return -1;
	//被除数为0返回0
	if (dividend == 0) return 0;
	//除数为1返回被除数
	if (divisor == 1) return dividend;
	//极端用例，负数的最大绝对值大于正数最大绝对值
	if (dividend==-2147483648 && divisor==-1) return 2147483647;
	if (dividend==-2147483648 && divisor==1) return -2147483648;
	//由于-2147483648取反会溢出，所以全部转成负整数
	int x = divisor > 0 ? -divisor : divisor;
	int y = dividend > 0 ? -dividend : dividend;
	//当被除数小于除数时，还可以除
	int ans = 0;
	while (y <= x) {
		int i = 1, xi = x << i;
		//当被除数加上除数的2倍、4倍、8倍还小于0时，继续加x<<i，注意x<<i仍然是负数
		while (xi < 0 && y - xi < 0) {
			i++;
			xi = x << i;
		}
		//由于是指数倍加上除数的倍数的绝对值，把被除数接近到差刚刚小于0的情况
		y -= (x << (i - 1));
		//被除数加上除数i-1的指数倍，商包含1<<(i-1)
        ans += (1 << (i - 1));
	}
	//异或取反，此时ans不存在溢出问题
    if (dividend > 0 ^ divisor > 0) ans = -ans;
    return ans;
}
```
