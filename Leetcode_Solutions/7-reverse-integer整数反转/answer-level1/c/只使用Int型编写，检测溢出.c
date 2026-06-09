### 代码

```c
int reverse(int x)
{
    int a, b;
	int y;

	if (x > 0) {
		b = INT_MAX;
	}
	else {
		b = INT_MIN;
	}
	y = 0;
	while (x) {
		a = x % 10;
		if (y && y + 1 && b / y < 10) {
			return 0;
		}		//注意，只有 * 10 可能溢出， + a 是肯定不会溢出的
		y = y * 10 + a;
		x /= 10;
	}
	return y;
}
```