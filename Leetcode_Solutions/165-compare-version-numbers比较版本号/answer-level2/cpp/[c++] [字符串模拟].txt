### 解题思路
![image.png](https://pic.leetcode-cn.com/95947e0f21390883c8d5fabfae2c800849d7fe5bbf577c41f7f799bc1d869e7c-image.png)


### 代码

```cpp
class Solution {
public:
	int compareVersion(string s1, string s2) {
		int i = 0, j = 0;
		while (i < s1.size() || j < s2.size()) {
			int x = i, y = j;
			while (x < s1.size() && s1[x] != '.') x++;
			while (y < s2.size() && s2[y] != '.') y++;
			int a = i == x ? 0 : atoi(s1.substr(i, x - i).c_str());
			int b = j == y ? 0 : atoi(s2.substr(j, y - j).c_str());
			if (a > b) return 1;
			if (a < b) return -1;
			i = x + 1, j = y + 1;
		}
		return 0;
	}
};
```