

### 代码

```cpp
class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) 
	{
		int flag;
		for (int i = 0; i < ransomNote.size(); ++i)
		{
			flag = 0;
			for (int j = 0; j < magazine.size(); ++j)
			{
				if (ransomNote[i] == magazine[j])
				{
					flag = 1;
					magazine[j] = '*';
                    break;
				}
			}
			if (!flag)
				return false;
		}
		return true;
	}
};
```