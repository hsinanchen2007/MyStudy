![hahaha.png](https://pic.leetcode-cn.com/a7b59ce7ae092352e71dcaeb5214437e9b49198f2545e9bd5309ae62ce71a317-hahaha.png)
```
class Solution {
public:
	bool isScramble(string s1, string s2) {
		if (s1.empty())
			return true;
		int n = s1.length();
		if (n == 1)
			return s1[0] == s2[0];
		if (n == 2)
			return s1 == s2 || (s1[0] == s2[1] && s1[1] == s2[0]);
		if (s1 == s2)
			return true;
		vector<int> letters(26, 0);
		for (int i = 0; i < n; ++i)
		{
			++letters[s1[i] - 'a'];
			--letters[s2[i] - 'a'];
		}
		for (int i = 0; i < 26; ++i)
		{
			if (letters[i] != 0)
				return false;
		}
		for (int i = 1; i < n; ++i)
			if (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i))
				|| isScramble(s1.substr(0, i), s2.substr(n - i)) && isScramble(s1.substr(i), s2.substr(0, n - i)))
				return true;
		return false;
	}
};
```
