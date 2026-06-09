### 解题思路
这不就是一个从大到小排序问题么，不知道为啥会设定为中等难度

### 代码

```cpp
class Solution {
public:
	int hIndex(vector<int>& citations) {
		sort(citations.begin(), citations.end(), greater<int>());
		for (int i = 0; i < citations.size(); i++) {
			 if (i >= citations[i]) return i;
		}
		return citations.size();
	}
};
```