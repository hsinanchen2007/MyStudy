简单的模拟题。将数字按位拆分，分别计算各位数字之积与各位数字之和，求差即可。
```
class Solution {
public:
	int subtractProductAndSum(int n) {
		int nProduct = 1;
		int nSum = 0;
		while (n) {
			int nMod = n % 10;
			nProduct *= nMod;
			nSum += nMod;
			n /= 10;
		}

		return nProduct - nSum;
	}
};
```
