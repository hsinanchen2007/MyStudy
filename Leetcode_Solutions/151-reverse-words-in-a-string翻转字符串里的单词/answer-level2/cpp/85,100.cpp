### 解题思路
从后往前取字符，遇空格或者结束时将反转的字符串加入结果字符串就OK


### 代码

```cpp
  class Solution {
  public:
	  string reverseWords(string s) {
		  string res;
		  string str;
		  for (int i = s.size() - 1; i >= 0; i--)
		  {
			  if (s[i] != ' ')
				  str.push_back(s[i]);
			  if ((s[i] == ' '||i==0) && !str.empty())
			  {
				  reverse(str.begin(), str.end());
				  res.append(str);
				  res.push_back(' ');
				  str.clear();
			  }
		  }
		  if (res.size() > 0)
			  res.erase(res.size() - 1, 1);
		  return res;
	  }
  };

```