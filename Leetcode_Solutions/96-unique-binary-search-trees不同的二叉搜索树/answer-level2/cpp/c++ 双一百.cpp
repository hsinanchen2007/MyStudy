![H)\[9{B7Y27IFR8~54LC0NEB.png](https://pic.leetcode-cn.com/a35bf1ffb49a65bccc2375d7cda080f955b34d828b0e7a4f776169adc8abef71-H\)%5B9%7BB7Y27IFR8~54LC0NEB.png)

### 代码

```cpp
class Solution {
public:
	int numTrees(int n) {
		if (n < 1)	return 1;
		auto d = vector<int>(n + 1, 0);
		d[0] = 1;
		d[1] = 1;
		for (int i = 2; i <= n; i++)
		{
			for (int j = 1; j <= i / 2; j++)
			{
				d[i] += 2 * d[i - j]*d[j-1];
			}
			if (i % 2 == 1)
			{
				d[i] += d[i / 2] * d[i / 2];
			}
		}
		return d[n];
	}
};
```