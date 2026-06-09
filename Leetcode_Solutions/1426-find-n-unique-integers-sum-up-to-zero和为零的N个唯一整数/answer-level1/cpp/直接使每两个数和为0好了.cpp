两个数一组，使他们和为0，若n为奇数，则最后一个数取0。

**代码**
```C++ []
class Solution {
public:
	vector<int> sumZero(int n) {
		vector<int> res;
		int k = n / 2;
		for (int i = 1; i < k + 1; i++) {
			res.push_back(i);
			res.push_back(-i);
		}
		if (n & 1)
			res.push_back(0);
		return res;
	}
};
```