void swap(char *a,  char *b)
{
	char temp = '\0';
	temp = *a;
	*a = *b;
	*b = temp;
}

void reverseWord(char *s, int first, int end)
{
	if (first == end)
	{
		return;
	}
	while(first < end)
	{
		swap(s+(first++), s+(end--));
	}
	return;   
}

char * reverseParentheses(char * s){
    if (NULL == s)
	{
		return NULL;
	}

	int len = strlen(s);
	
	char *result = NULL;
	result = (char *)malloc((len + 1) * sizeof(char));
	memset(result, '\0', (len + 1) * sizeof(char));

	int *arrNum = NULL;
	arrNum = (int *)malloc((len + 1) * sizeof(int));
	memset(arrNum, 0, (len + 1) * sizeof(int));

	int count = 0;
	for (int i = 0; i < len; i++)
	{
		if (s[i] == '(')
		{
			arrNum[count++] = i;
		}
		else if (s[i] == ')')
		{
			reverseWord(s, arrNum[count - 1], i);
			arrNum[count--] = '\0';
		}
	}

	count = 0;
	for (int i = 0; i < len; i++)
	{
		if (s[i] >='a' && s[i] <= 'z')
		{
			result[count++] = s[i];
		}
	}

	return result;
}
