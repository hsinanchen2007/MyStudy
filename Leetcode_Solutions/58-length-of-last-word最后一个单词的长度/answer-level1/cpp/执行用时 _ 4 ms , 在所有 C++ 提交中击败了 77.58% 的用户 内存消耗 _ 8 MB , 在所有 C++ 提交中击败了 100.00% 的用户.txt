### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
	int lengthOfLastWord(string s) {
		string ss = "";
		int n = s.size();
		for (int i = n-1; i >=0; i--) {
			if (s[i] != ' ') { 
				ss += s[i];
			}
			if (ss != ""&&s[i] == ' ') {
				break;
			}
		}
		return ss.size();
	}
};
```