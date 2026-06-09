### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
   int countCharacters(vector<string>& words, string chars)
	{
		vector<int> vec(256, 0);
        int nSize = chars.size();
		for (int i = 0; i < nSize; i++)
		{
			vec[chars[i]]++;
		}
		int nRes = 0;
        nSize = words.size();
		for (int i = 0; i < nSize; i++)
		{
			if (IsCover(words[i], vec))
			{
				nRes += words[i].size();
			}
		}
		return nRes;
	}

	bool IsCover(string words, vector<int> vec)
	{
		int nSize = words.size();
		for (int i = 0; i < nSize; i++)
		{
			if (vec[words[i]] == 0)
			{
				return false;
			}
            vec[words[i]]--;
		}
		return true;
	}
};
```