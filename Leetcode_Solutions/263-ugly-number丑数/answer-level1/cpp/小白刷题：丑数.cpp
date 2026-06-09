送分题，正整数除以所有2、3、5因数，剩下1就是丑数

代码：
```
class Solution {
public:
	bool isUgly(int num) {
		if (num > 0) {
			while (!(num % 2))
				num /= 2;
			while (!(num % 3))
				num /= 3;
			while (!(num % 5))
				num /= 5;
			return num == 1;
		}
		return false;
	}
};
```
