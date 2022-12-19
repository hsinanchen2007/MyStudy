字符串长度差大于1的肯定false。
字符串长度差等于0的如果为true则只能最多发生一次替换，其余对应位相等。
字符串长度差等于1的如果为true则长字符串只能最多发生一次删除变成短字符串，其余对应位相等。
```C++ []
class Solution {
public:
	bool oneEditAway(string first, string second) {
		bool diff = false;
		int cha = abs((int)first.length() - (int)second.length());
		if (cha > 1)
			return false;
		else if (cha == 0) {
			for (int i = 0; i < first.length(); i++) {
				if (first[i] != second[i]) {
					if (!diff)
						diff = true;
					else
						return false;
				}
			}
		}
		else if(first.length() > second.length()){
			for (int i = 0; i < second.length(); i++) {
				if (!diff) {
					if (first[i] != second[i]) {
						diff = true;
						i--;
					}
				}
				else {
					if (first[i + 1] != second[i])
						return false;
				}
			}
		}
		else {
			for (int i = 0; i < first.length(); i++) {
				if (!diff) {
					if (second[i] != first[i]) {
						diff = true;
						i--;
					}
				}
				else {
					if (second[i + 1] != first[i])
						return false;
				}
			}
		}
		return true;
	}
};
```
