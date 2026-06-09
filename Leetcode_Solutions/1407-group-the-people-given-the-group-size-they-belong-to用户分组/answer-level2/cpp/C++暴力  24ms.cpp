**很简单的做法，就是用buff存放下标，根据数组里面的下标是否满足，存入到resr**
*需要注意的就是每次加入之后需要跳出循环*

```
class Solution {
public:
	vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
		vector<vector<int>>res;
		int len = groupSizes.size();
		vector<bool>flag(len, false);
		vector<int>buff;
		for (int i = 0; i < len; ++i)
		{
			if (!flag[i])
				for (int j = i; j < len; ++j)
				{
					//500的长度那就暴力吧
					if (!buff.size())
					{
						//buff为空
						if (!flag[j])
						{
							buff.push_back(j);
							flag[j] = true;
						}
						if (buff.size() == groupSizes[buff[0]])
						{
							res.push_back(buff);
							buff.clear();
							//如果不跳出，就可能出现前面的没办法加进去
							break;
						}
					}
					else
					{
						if (groupSizes[buff[0]] == groupSizes[j] && !flag[j])
						{
							buff.push_back(j);
							flag[j] = true;
							if (buff.size() == groupSizes[buff[0]])
							{
								res.push_back(buff);
								buff.clear();
								break;
							}
						}
					}
				}
		}
		return res;
	}
};
```
