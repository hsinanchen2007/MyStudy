执行用时 :28 ms, 在所有 C++ 提交中击败了9.77%的用户
内存消耗 :9.1 MB, 在所有 C++ 提交中击败了64.38%的用户

### 代码

```cpp
class Solution 
{
public:
	bool isIsomorphic(string s, string t) 
	{
		char c1, c2;
		int flag = 0;
		int i, j;
		if (s.size()==0) return true;
		while (flag < s.size())
		{
			if (s[flag] == '*')
			{
				flag++;
				continue;
			}
			i = flag;
			j = flag;
			c1 = s[i];
			c2 = t[i];
			while (i < s.size())
			{
				if ((s[i] != c1) && (t[i] != c2))
					i++;
				else
					if ((s[i] != c1)&&(t[i] == c2))
						return false;
					else
					{
						j = i;
						if (t[j] == c2)
						{
							t[j] = '*';
							s[i] = '*';
							i++;
						}
						else
							return false;
					}

			}
			flag++;
		}
		return true;
	}
};
```