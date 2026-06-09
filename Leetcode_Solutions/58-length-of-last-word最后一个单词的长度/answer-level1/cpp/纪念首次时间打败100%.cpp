初始长度为0，从最后开始遍历，直到遇到第一个len非零后的空格

class Solution {
public:
	int lengthOfLastWord(string s) {
		int len = 0;
		for (int i = s.length() - 1; i >= 0; --i)
		{
			if (s[i] >= 65 && s[i] <= 122)
			{
				len++;
			}
			if (s[i] == ' ' && len != 0)
			{
				break;
			}
		}
		return len;
	}
};