### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
	bool canPermutePalindrome(string s) {
        if (s.size() == 0||s.size()==1) return true;
		map<char, int> hash;
		for (int i = 0; i < s.size(); i++) {
			if (hash.find(s[i]) == hash.end()) hash[s[i]] = 1;
			else hash[s[i]]++;
		}
		map<char, int>::iterator it;
		if (s.size() % 2 == 0) {
			for (it = hash.begin(); it != hash.end(); it++) {
				if ((it->second)%2==1) {
					return false;
				}
			}
			return true;
		}
		else {
			int count = 0;
			for (it = hash.begin(); it != hash.end(); it++) {
				if ((it->second) % 2 == 1) {
					count++;
				}
				if (count > 1) return false;
			}
			return true;
		}
	}
};
```