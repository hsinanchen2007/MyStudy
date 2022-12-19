### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        int m = s.size();
	string res(s);
	if (m == 0) { return 0; }
	for (int i = n; i - n < m; i++) {
		res[i - n] = s[i%m];
	}
	return res;
    }
};
```