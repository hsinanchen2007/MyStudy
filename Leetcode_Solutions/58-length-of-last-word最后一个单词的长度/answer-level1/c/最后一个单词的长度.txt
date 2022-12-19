遍历一次字符串
1：字符串末尾没有空格，在遍历字符串时非空格 last_len++，遇到空格时last_len置0
2：字符串末尾有空格，在遍历字符串时非空格 last_len++，但是在遇到空格时需要判断当前字符
   和下一个字符是否不同且没有到字符串尾时才把last_len置0

/*输入的字符串以'\0'结尾*/
int lengthOfLastWord(char * s)
{
	int s_len = 0;
	int last_len = 0;

	s_len = 0;
	while (s[s_len] != '\0')
	{
		if (s[s_len] != ' ')
		{
			last_len++;
		}

		if ((s[s_len] == ' ')&&((s[s_len+1] != '\0')&&(s[s_len+1] != ' ')))
		{
			last_len = 0;
		}
		s_len++;
	}
	return last_len;
}