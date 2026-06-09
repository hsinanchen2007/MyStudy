执行用时 : 0 ms, 在Length of Last Word的C提交中击败了100.00% 的用户
内存消耗 : 7 MB, 在Length of Last Word的C提交中击败了80.24% 的用户


```
int lengthOfLastWord(char * s){

 int WordLength = 0;
int WordLengthCount = 0;
	
	while(*s != '\0')
	{
		while(*s != ' ')
		{
			while((*s != ' ') && (*s != '\0'))
			{
				WordLengthCount++;
				WordLength = WordLengthCount;
				s++;
			}
			if(*s == '\0')
				return WordLength;
			s++;
			WordLengthCount = 0;
		}
		if(*s == '\0')
			return WordLength;
		s++;
	}
	return WordLength;
}
```