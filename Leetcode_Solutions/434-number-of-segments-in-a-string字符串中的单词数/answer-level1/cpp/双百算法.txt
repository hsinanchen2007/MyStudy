执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :6.1 MB, 在所有 C++ 提交中击败了100.00%的用户

### 代码

```cpp
class Solution {
public:
	int countSegments(string s) 
	{
		int res = 0;
		int flag=1;
		if (s.size() == 0) return res;
		for (int i = 0; i < s.size(); ++i)
		{
			if ((s[i]!=' ') && flag)
			{
				res++;
				flag = 0;
			}
			if (s[i] == ' ')
				flag = 1;
	    }
		return res;
	}
};
```