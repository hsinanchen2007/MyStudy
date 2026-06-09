### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
	bool CheckPermutation(string s1, string s2) {
		if (s1.size()!=s2.size()) {
			return false;
		}
		int res = 0;
		for (int i = 0; i < s1.size(); i++) {
			res = res ^ s1[i] ^ s2[i];
		}
		if (res!=0) {
			return false;
		}
		return true;
	}
};
```