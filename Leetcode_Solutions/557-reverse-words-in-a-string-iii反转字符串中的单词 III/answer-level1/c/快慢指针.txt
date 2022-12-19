```
void reverseWord(char *s, int start, int end)
{
	while (start < end)
	{
		char tmp = s[end];
		s[end] = s[start];
		s[start] = tmp;
		start++;
		end--;
	}

}
char * reverseWords(char * s) {
	int lenth = strlen(s);
	int i = 0, j = 0;
	while (j < lenth)
	{
		if ( ' ' ==(s[j]) || ('\0' == s[j]))
		{
			reverseWord(s, i, j-1);
			j++;
			i = j;
		}
		else if ((lenth - 1) == j)
		{
			reverseWord(s, i, j);
			j++;
		}
		else
		{
			j++;
		}
	}
	return s;
}

```
