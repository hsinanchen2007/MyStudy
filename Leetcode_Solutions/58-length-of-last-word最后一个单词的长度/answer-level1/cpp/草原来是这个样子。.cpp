### 解题思路
看了别人的代码，自己又写了一遍。就是从后往前数。

### 代码

```cpp
class Solution {
public:
int lengthOfLastWord(string s) {
	if (s.length() == 0)return 0;
	//int count = 0;
	int last = 0;
	int i;
	for (i = s.length()-1; i > -1; i--) {
		if (s[i] == ' ')continue;
		else break;
	}
	while (i>-1&&s[i] != ' ') {
		last++;
		i--;
	}
	return last;
}

};
```