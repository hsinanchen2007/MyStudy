送分题，一元二次方程k^2+k-2n=0的正数解向下取整

代码：
```
class Solution {
public:
	int arrangeCoins(int n) {
		return (int)((sqrt(8.0 * n + 1.0) - 1.0) / 2.0);
	}
};
```
