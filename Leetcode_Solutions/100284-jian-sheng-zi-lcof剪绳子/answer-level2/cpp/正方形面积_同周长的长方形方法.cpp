### 解题思路
小学学过的同周长情况下
正方形面积>长方形
本题是上述问题的N维情况，每条边长度越接近，则最后的乘积越大
### 代码

```cpp
class Solution {
public:
int cuttingRope(int n) {
	int max_value = 0;
	for (int i = 2; i <= n; i++) {
		int k = n / i;
		int b = n % i;
		int value = 1;
		for (int j = 0; j < i; j++, b--) {
			if (b > 0)value *= (k + 1);
			else value *= k;
		}
		max_value = max(max_value, value);
	}
	return max_value;
}
};
```