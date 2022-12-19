### 解题思路
服了，完全想不到有这么多种可能。我提交了五次才通过。

### 代码

```cpp
class Solution {
public:
int lengthOfLastWord(string s) {
	if (s.length()==0)return 0;
	int count = 0;
	int last = 0;
	for (int i = 0; i <s.length(); i++) {
		if (i < s.length() - 1) {
			if (s[i] == ' ' && s[i + 1] != ' ') {
				//if (count > max)max = count;
				//if (i + 1 == s.length()&&s[i]!=' ')count++;
				last = count;
				count = 0;
			}
			else if (s[i] == ' ' && s[i + 1] == ' ')
				continue;
			else count++;
		}
		else
			if(s[s.length()-1] !=' ')count++;
	}
	if (count)last = count;
	return last;
}

};
```