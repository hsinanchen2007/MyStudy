### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
	bool isFlipedString(string s1, string s2) {
		if (s1.size() != s2.size()) return false;
		else {
            s2+=s2;
			if (s2.find(s1) != string::npos) return true;
			else return false;
		}
		
	}
};
```