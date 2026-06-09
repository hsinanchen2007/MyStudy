### 解题思路
此处撰写解题思路

### 代码

```c

char * reverseWords(char * s)
{
    if(*s == '\0')
    return s;

	int lenth = strlen(s), i = 0, count = 0;
	char *t = s+lenth-1;
	char *word = NULL;
	char *s1 = (char *)malloc(sizeof(char)*(lenth+1));
	memset(s1, 0, sizeof(char)*(lenth+1));
	
	while(*s == 32 )
	s++;
	
	while(*(t-i) == 32)
    {
	    *(t-i) = '\0', i++;
        if(i >= lenth)
        break;
    }
	
	for(; t >= s; t--)
	{
		if(*t == 32)
		count++;
		
		if((*t == 32 && *(t-1) != 32) || t == s)
		{
			if(t != s)
			{
				word = t+count;
				*t = '\0', count = 0;
			} 
			else
				word = t;

		strcat(s1, word);
		if(t != s)
		strcat(s1, " ");
		}
	}
	 
	return s1;
} 
```