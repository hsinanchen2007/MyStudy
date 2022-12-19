### 递归+sprintf转换计数count为字符串
此处撰写解题思路

### 代码

```c
char * countAndSay(int n){
	if(n<=1)
	{
		char *res = "1";
		return res;
	}
	char *res = countAndSay(n-1);
	char *str = (char*)malloc(sizeof(char)*10); 
	char *s = (char*)malloc(sizeof(char)*5000);
	int count = 1;
	int num = 0;
	int i;
	for(i=1;i<strlen(res);i++)
	{
		if(res[i]!=res[i-1])
		{
			sprintf(str,"%d",count);
			for(int k=0;k<strlen(str);k++)
			{
				s[num++] = str[k];
			}
			s[num++] = res[i-1];
			count = 1;
		}
		else
		{
			count++;
		}
	}
	sprintf(str,"%d",count);
	for(int k=0;k<strlen(str);k++)
	{
		s[num++] = str[k];
	}
	s[num++] = res[i-1];
	s[num] = '\0';
	return s;
}
```