送分题，遍历0到根号(c/2)

代码：
```
class Solution {
public:
	bool judgeSquareSum(int c) {
		int flag = (int)sqrt(c / 2);
		for (int i = 0; i <= flag; i++) {
			if ((int)sqrt(c - i * i) * (int)sqrt(c - i * i) == c - i * i)
				return true;
		}
		return false;
	}
};
```
