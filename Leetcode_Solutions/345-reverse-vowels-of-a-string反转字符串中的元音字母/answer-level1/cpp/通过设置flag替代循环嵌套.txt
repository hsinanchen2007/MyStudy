执行用时 :4 ms, 在所有 C++ 提交中击败了99.20%的用户
内存消耗 :9.2 MB, 在所有 C++ 提交中击败了100.00%的用户

时间复杂度o(n)
空间复杂度o(1)

至于下面代码中的if判断，可以写成更简练的形式，比如写成set或者函数，我这里就没有改了
主要是想分享一下思想

### 代码

```cpp
class Solution {
public:
	string reverseVowels(string s) 
	{
		int i = 0, j = s.size() - 1;
		int flag1 = 0, flag2 = 0;
		while (i < j)
		{
			if (s[i] != 'a' && s[i] != 'o' && s[i] != 'e' && s[i] != 'i' && s[i] != 'u'&& s[i] != 'A' && s[i] != 'E' && s[i] != 'I' && s[i] != 'O' && s[i] != 'U')
			{
				++i;
				flag1 = 0;
			}
			else
				flag1 = 1;
			if (s[j] != 'a' && s[j] != 'o' && s[j] != 'e' && s[j] != 'i' && s[j] != 'u'&& s[j] != 'A' && s[j] != 'E' && s[j] != 'I' && s[j] != 'O' && s[j] != 'U')
			{
				--j;
				flag2 = 0;
			}
			else
				flag2 = 1;
			if (flag1 && flag2)
			{
				char t;
				t = s[j];
				s[j] = s[i];
				s[i] = t;
                		++i;
                		--j;
			}
			
		}
		return s;
	}
};
```