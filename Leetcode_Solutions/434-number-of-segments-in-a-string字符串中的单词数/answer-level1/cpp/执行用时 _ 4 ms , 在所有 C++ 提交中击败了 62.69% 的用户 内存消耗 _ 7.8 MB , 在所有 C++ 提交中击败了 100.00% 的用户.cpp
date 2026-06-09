### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
	int countSegments(string s) {
		if (s == "") return 0;
		int count = 0;
		s = s + ' ';
		string ss = "";
		for (int i = 0; i < s.size(); i++) {
			if ((i + 1 < s.size()) && (s[i] == ','&&s[i + 1] == ' ')&&ss!="") {
				count++;
				i++;
				ss = "";
				continue;
			}
			else if (s[i] == ' '&&ss!=""&&ss!=" ") {
				count++;
				ss = "";
			}
				
			else {
				if (ss == " ") ss = "";
				ss += s[i];
			}

		}
		if (count != s.size())
			return count;
		else return 0;
	}
};
```