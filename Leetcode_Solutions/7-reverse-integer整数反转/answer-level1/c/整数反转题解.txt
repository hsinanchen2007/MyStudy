### 解题思路
数字转字符,再将字符转数字,使用长整型防运行溢出错误

### 代码

```c
#define N 10
int reverse(int x) {
	int ans[N] = { 0 };
	int length = 0;

	long long int num = x;

	bool flag = true;      //正负数标签

	if (num < 0) {
		flag = false;
		num *= -1;
	}

	for (; num > 0; num /= 10) {
		int tmp = num % 10;

		if (length < N)
		{
			ans[length++] = tmp;
		}
		else {
			return 0;
		}

	}

	long long int ret = 0;

	//字符串转整数
	for (int i = 0; i < length; i++) {
		ret *= 10;

		if (ret > 0x7FFFFFFF) {
			return 0;
		}

		if (i == 0 && ans[i] == 0) {
			continue;
		}
		else {
			ret += ans[i];
		}
	}

	if (!flag) ret *= -1;

	return ret;
}
```