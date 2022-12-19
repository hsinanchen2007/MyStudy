```
class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows == 1)return s;
		int len = s.size();
		vector<string> vec;
		for (int i = 0; i < numRows; i++)
		{
			vec.push_back({});
		}

		int dir = 1;
		int index = 0;
		for (int i = 0; i < len; i++)
		{
			vec[index].push_back(s[i]);
			index = index + dir;
			if (index == numRows - 1)
			{
				dir = -1;
			}
			else if (index == 0)
			{
				dir = 1;
			}
		}
		string out = {};
		for (int i = 0; i < numRows; i++)
		{
			out += vec[i];
		}
		return out;
	}
};
```
