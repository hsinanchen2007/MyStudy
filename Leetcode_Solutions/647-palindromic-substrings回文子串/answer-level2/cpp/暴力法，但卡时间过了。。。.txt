```
using namespace std;
class Solution {
public:
	int countSubstrings(string s) {
		if (s.empty())
			return 0;
		int ans = 0;
		for (int i = 0; i < s.size(); i++)
		{
			for (int j = 0; j + i < s.size(); j++)
				ans += isPstr(s, j, j+i);
		}
		return ans;
	}
	int isPstr(string str, int i, int j)
	{
		while (i < j)
		{
			if (str[i] == str[j])
				i++, j--;
			else
				return 0;
		}
		return 1;
	}
};
```
