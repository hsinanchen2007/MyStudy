### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
	int fib(int n) {
		if (n==0) {
			return 0;
		}
		if (n==1) {
			return 1;
		}
		int f0 = 0, f1 = 1;
		int mod = 1e9 + 7;
		int fn = 0;
		for (int i = 2; i <= n;i++) {
			fn = (f0 + f1)%mod;
			f0 = f1;
			f1 = fn;
		}
		return fn;
	}
};
```