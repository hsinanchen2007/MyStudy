第一反应递归，但会造成大量重复运算，容易超时

可考虑用两临时变量存储数列前两项，不断迭代更新得到结果

代码：
```
class Solution {
public:
	int fib(int N) {
		if (N < 2)
			return N;
		else {
			int a = 0, b = 1;
			for (int i = 2; i <= N; i++) {
				a = a + b;
				swap(a, b);
			}
			return b;
		}
	}
};
```
