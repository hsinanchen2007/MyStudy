整就完事了
```
class Solution {
public:
	bool checkRecord(string s) {
		int num=0;
		if (s[0] == 'A') num++;
		if (s[1] == 'A') num++;
		if (num > 1) return false;
		if (s[0] == 'L'&&s[1] == 'L'&&s[2]=='L') return false;
		for (int i = 2; i < s.size(); i++)
		{
			if (num >1) return false;
			if (s[i] == 'A') num++;
			if (s[i-2] == 'L'&&s[i-1] == 'L'&&s[i]=='L') return false;
		}
		return true;

	}
};
```
