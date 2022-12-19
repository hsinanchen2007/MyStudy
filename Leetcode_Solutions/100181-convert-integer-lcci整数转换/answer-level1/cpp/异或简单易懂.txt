### 解题思路
先将两数异或，结果是负数变为正数，再计算结果的1的个数。

### 代码

```cpp
class Solution {
public:
	int convertInteger(int A, int B) {
		int result = 0;
		if (A < 0 && B>0)
			result++;
		if (A > 0 && B < 0)
			result++;
		int a = A ^ B;
		if (a < 0)
		{
			a = 2147483647 + a + 1;
		}
		while (a)
		{
			result = result + a%2;
			a = a / 2;
		}
		return result;
	}
};
```