### 解题思路
1、使用strtok根据空格分割字符串
2、对分割后的每隔字符串进行首字母判断和对应的操作处理
注意：
1、非元音字母开头的字符串需要判断长度是否为1
2、注意结尾添加'\0'去除最后一个空格

### 代码

```c
char * toGoatLatin(char * S){
	char *ret = (char*)malloc(sizeof(char) * 9999);
	memset(ret, 0, 9999);
	int i = 0, index = 1;
	char *p;
	p = strtok(S, " ");
	while(p != NULL)
	{
		if(p[0] == 'a' || p[0] == 'e' || p[0] == 'i' || p[0] == 'o' || p[0] == 'u' || 
				p[0] == 'A' || p[0] == 'E' || p[0] == 'I' || p[0] == 'O' || p[0] == 'U' )
		{
			strcat(ret, p);
			ret[strlen(ret)] = 'm';
			ret[strlen(ret)] = 'a';
			for(i = 0; i < index; i++)
			{
				ret[strlen(ret)] = 'a';
			}
			ret[strlen(ret)] = ' ';
			index++;
		}
		else
		{
			if(strlen(p) > 1)
			{
				strcat(ret, &p[1]);
				ret[strlen(ret)] = p[0];
			}
			else
			{
				strcat(ret, p);
			}
			ret[strlen(ret)] = 'm';
			ret[strlen(ret)] = 'a';
			for(i = 0; i < index; i++)
			{
				ret[strlen(ret)] = 'a';
			}
			ret[strlen(ret)] = ' ';
			index++;
		}
		p = strtok(NULL, " ");
	}
	
	ret[strlen(ret)-1] = '\0';
	return ret;

}
```