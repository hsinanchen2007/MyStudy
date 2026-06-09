
sqrt(x) = a，可以看做f(x) = x^2 - b = 0的根

注意判断的时候用除法不用乘法，避免溢出

```
class Solution {
public:
	int mySqrt(int x) {
		int x0 = x;
		int x1;

		if (x == 0 || x == 1)
		{
			return x;
		}

		while (true)
		{
			x1 = x0 / 2 + x / x0 / 2;

			if ((x1 == x / x1) || (x1 < x / x1 && x1 + 1 > x / (x1 + 1)))
			{
				return x1;
			}
			else if (x1 + 1 == x / (x1 + 1))
			{
				return x1 + 1;
			}
			else
			{
				x0 = x1;
			}
		}
	}
};
```


