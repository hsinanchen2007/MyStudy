```cpp
class Solution {
public:
	int longestPalindrome(string s)
	{
	    int oddNum = 0 , cnt[256] = { 0 };
		for (auto ch : s) ++cnt[ch];
		for (auto c : cnt) if (c & 1) ++oddNum;

		int N = s.size();
		return min(N, N - oddNum + 1);
	}
};
```