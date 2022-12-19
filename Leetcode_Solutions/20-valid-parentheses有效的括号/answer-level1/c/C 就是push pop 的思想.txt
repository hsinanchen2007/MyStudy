### 解题思路
此处撰写解题思路

### 代码

```c


bool isValid(char * s)
{
	int lenth = strlen(s), count = 0;
	char *p = (char *)malloc(sizeof(char)*(lenth+1));
	memset(p, 0, sizeof(char)*(lenth+1)); 
	
	for(int i = 0; i < lenth; i++)
	{
		if(s[i] == '(' || s[i] == '[' || s[i] == '{')
		p[++count] = s[i];
		
		else if(s[i] == p[count]+1 || s[i] == p[count]+2)
		count--; 
		
		else
		return 0;
	}
	
	return count == 0 ? 1 : 0;
}
```