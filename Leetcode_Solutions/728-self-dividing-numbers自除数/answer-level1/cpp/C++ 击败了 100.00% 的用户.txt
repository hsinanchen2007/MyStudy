### 解题思路
![1.png](https://pic.leetcode-cn.com/24e25f5c34042ccb1aeff86bfc48ed5dca746bf8a16390548909316cf3960135-1.png)

### 代码

```cpp
class Solution {
public:
	bool isSelfDivideNumber(int i) {
		int cur = i;
		while (cur) {
			int digit = cur % 10;
			if (digit == 0) return false;
			if (i % digit != 0) return false;
			cur /= 10;
		}
		return true;
	}

	vector<int> selfDividingNumbers(int left, int right) {
		vector<int>res;
		for (int i = left; i <= right; i++)
			if (isSelfDivideNumber(i))res.push_back(i);
		
		return res;
	}
};
```