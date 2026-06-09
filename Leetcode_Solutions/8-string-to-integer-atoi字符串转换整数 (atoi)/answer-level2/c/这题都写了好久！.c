### 解题思路
此处撰写解题思路

### 代码

```c
long myAtoi(char * str)
{
	int min = -2147483648;
	int max = 2147483647;
	
	long result=0;
	char *p = str;
	int sign = 1;
	if( *p != ' ' && *p != '-' && *p != '+'  && (*p > 57 || *p < 48) )
	{
		return 0;
	}
	//if((*p >= 'A' && *p <='Z') || *p >= 'a' && *p <= 'z' )return 0;
	while(*p == ' ')p++;

	int flag = 0;
	while(*p == '-' || *p == '+')
	{		
		if(*p == '-')
		{
			sign=-1;
			flag++;
			p++;
		}
		if(*p == '+')
		{
			flag++;
			sign=1;
			p++;
		}
		if(flag >= 2)return 0;
	}

	while(*p != ' ' && *p !='\0' && *p != '.' )
	{
		if(*p > 57 || *p < 48)break;
		result = result*10 + (*p-48);

        if(result*sign > max)return max;
	    if(result*sign < min)return min;
		p++;
	}
	return result*sign;
}
```