### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
	string customSortString(string S, string T) {
		string res;
		for (int i = 0; i < S.size(); i++) {
			char temp = S[i];
			size_t pos;
			do {
				pos = T.find(temp);
				if (pos != string::npos) {
					res += T[pos];
					T.erase(pos, 1);
				}
			} while (pos!=string::npos);
			
		}
		return res + T;
	}
};
```