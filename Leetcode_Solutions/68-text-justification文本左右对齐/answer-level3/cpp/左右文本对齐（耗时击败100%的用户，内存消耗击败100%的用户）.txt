![微信图片_20200320021444.png](https://pic.leetcode-cn.com/4084cde8da08cac48126cf4c4b3d0b9a681f7c3242083fb5508bde15c269f02e-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200320021444.png)


### 解题思路
就是考虑的情况多，本身并没有什么难度

### 代码
```cpp
class Solution {
public:
  vector<string> fullJustify(vector<string>& words, int maxWidth) {
	vector<vector<string>> res;
	map<int, string>wordsSqe;
	int n = 0;
	int length = 0;
	int step = 0;
	vector<string> temp;
	while (n < words.size())
	{
		length += words[n].size();
		if (length < maxWidth)
		{
			temp.push_back(words[n]);
			length++;
		}
		else if (length == maxWidth)
		{
			temp.push_back(words[n]);
			res.push_back(temp);
			length = 0;
			temp.clear();
		}
		else if (length > maxWidth)
		{
			res.push_back(temp);
			temp.clear();
			temp.push_back(words[n]);
			length = words[n].size();
			length++;
		}
		n++;
	}
    if(!temp.empty())
	res.push_back(temp);
	vector<string> result;
	for (int i = 0; i < res.size(); i++)
	{
		string tempString;
		int totalLength = 0;
		for (int j = 0; j < res[i].size(); j++)
			totalLength += res[i][j].size();
		int nullNumber;
		if (i != res.size() - 1)
		{
			if (res[i].size() > 1)
			{
				nullNumber = (maxWidth - totalLength) / (res[i].size() - 1);
				int fullNumber = (maxWidth - totalLength) % (res[i].size() - 1);
				int count = 0;
				for (int j = 0; j < res[i].size(); j++)
				{
					if (j != res[i].size() - 1)
					{
						if (fullNumber == 0)
							tempString.append(res[i][j]).append(nullNumber, ' ');
						else
						{
							if (count != fullNumber)
							{
								tempString.append(res[i][j]).append(nullNumber + 1, ' ');
								count++;
							}
							else
								tempString.append(res[i][j]).append(nullNumber, ' ');
						}
					}
					else
						tempString.append(res[i][j]);
				}
			}
			else
				tempString.append(res[i][0]).append(maxWidth - totalLength, ' ');
		}
		else
		{
			if (res[i].size() > 1)
			{
				nullNumber = maxWidth - totalLength - (res[i].size() - 1);
				for (int j = 0; j < res[i].size(); j++)
				{
					if (j != res[i].size() - 1)
						tempString.append(res[i][j]).append(" ");
					else
						tempString.append(res[i][j]).append(nullNumber, ' ');
				}
			}
			else
				tempString.append(res[i][0]).append(maxWidth - totalLength, ' ');
		}
		result.push_back(tempString);
	}
	return result;
}
};
```