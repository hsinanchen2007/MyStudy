当字符串为末尾存在空格时，如"Hello      ",要先把末尾的空格清除。

附上代码，主要思路是从后往前遍历字符串，遇到合格字符时，就压入栈中，最后返回栈的长度即可。

class Solution {
public:
	int lengthOfLastWord(string s)
	{

		if (s.size() == 0)
			return 0;

		stack<char> mystack;
		int i = s.size() - 1;

		while (i >= 0 && s[i] == ' ')
			i--;
		
		while (i >= 0)
		{
			if (s[i] == ' ')
				break;
			mystack.push(s[i]);
			i--;
		}
		return mystack.size();
	}
};