### 解题思路
动态规划

### 代码

```cpp
class Solution {
public:
    int cuttingRope(int n) {
		if (n == 2)return 1;
		if (n == 3)return 2;
		int* bol = new int[n + 1];
		bol[0] = 0;
		bol[1] = 1;
		bol[2] = 2;
		bol[3] = 3;
		int maxx = 0;
		for (int i = 4; i <= n; ++i) {
			for (int j = 1; j <= i / 2; ++j) {
				int num = bol[j] * bol[i - j];
				maxx = max(maxx, num);
			}
			bol[i] = maxx;
		}
		return bol[n];
    }
};
```