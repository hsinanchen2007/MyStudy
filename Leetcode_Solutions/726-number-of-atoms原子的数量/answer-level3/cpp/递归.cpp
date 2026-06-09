### 解题思路
递归

### 代码

```cpp
class Solution
{
public:
	string countOfAtoms(string &formula)
	{
		map<string, int> count;
		string res;
		_countOfAtoms(formula, 0, count);
		for(auto const &it :count)
		{
			if(it.second == 1)
			{
				res  += it.first;	
			}
			else
			{
				res  += it.first + to_string(it.second);
			}				
		}
		return res;
	}

	int _countOfAtoms(string &formula, int index, map<string, int> &count)
	{
		string elem = "";
		int cnt = 0;

		for (int i = index; i < formula.length();)
		{
			if (formula[i] >= 'A' && formula[i] <= 'Z')
			{
				if (!elem.empty())
				{
					update_map(count, elem, cnt);	
				}
				elem = formula[i];
				cnt = 1;
				i++;
			}
			else if (formula[i] >= 'a' && formula[i] <= 'z')
			{
				elem += formula[i];
				i++;
			}
			else if (formula[i] >= '0' && formula[i] <= '9')
			{
				cnt = 0;
				while (i < formula.length())
				{
					if (formula[i] >= '0' && formula[i] <= '9')
					{
						cnt = 10 * cnt + formula[i] - '0';
						i++;
					}
					else
					{
						break;
					}
				}
			}
			else if (formula[i] == '(')
			{
				map<string, int> t_map;
				i = _countOfAtoms(formula, i + 1, t_map);
				int t_cnt = 0;
				while (i < formula.length())
				{
					if (formula[i] >= '0' && formula[i] <= '9')
					{
						t_cnt = 10 * t_cnt + formula[i] - '0';
						i++;
					}
					else
					{
						break;
					}
				}
				for (auto const &it : t_map)
				{
					update_map(count, it.first, it.second*t_cnt);					
				}
			}
			else
			{
				update_map(count, elem, cnt);
				return i + 1;
			}
		}
		update_map(count, elem, cnt);
		return formula.length() - 1;
	}

	void update_map(map<string, int> &_map, const string & key, int value)
	{
		if(value == 0)
		{
			return;
		}
		if(_map.find(key) == _map.end())
		{
			_map[key] = value;
		}
		else
		{
			_map[key] += value;
		}
	}
};
```