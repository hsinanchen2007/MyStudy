### 解题思路


### 代码

```cpp
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		string res;
		if (strs.size() == 0)
			return res;

		int pos = 0;
		for (int i = 0; i < strs[0].size(); i++)
		{
			int ifmatch = true;
			for(int j=1;j<strs.size();j++)
				if (strs[j][i] != strs[0][i])
				{
					ifmatch = false;
					return res;
				}
			if (ifmatch)
				res.push_back(strs[0][i]);
		}

		return res;

	}
};

```