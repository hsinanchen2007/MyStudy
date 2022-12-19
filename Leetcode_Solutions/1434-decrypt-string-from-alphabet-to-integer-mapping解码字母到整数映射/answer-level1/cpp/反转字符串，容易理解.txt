### 解题思路
反转s之后直接判断#

### 代码

```cpp
class Solution {
public:
	string freqAlphabets(string s) {
		std::reverse(s.begin(), s.end());
		string ret;
		for (int i = 0; i < s.size(); i++){
			if (s[i] == '#'){
				if (s[i+2] == '1'){
					ret.push_back(s[i+1] + 58);
				}
				else{
					ret.push_back(s[i+1] + 68);
				}
				i = i + 2;
			}
			else {
				ret.push_back(s[i] + 48);

			}
		}
		std::reverse(ret.begin(), ret.end());
		return ret;
	}
};
```