### 解题思路
此处撰写解题思路

### 代码

```c
int myAtoi(char * str){
   	int i=0;
	int str_sign = 1;
	long sum = 0;

	while(str[i] == ' ')
	{
		i++;
	}

	if(str[i] == '-')
		str_sign = 0;
	if(str[i] == '-' || str[i] == '+')
		i++;

	while(str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		sum = sum *10 + str[i]-'0';
		i++;
		if((int)sum != sum)
			return (str_sign == 1)?INT_MAX:INT_MIN;
	}
	return (str_sign == 0)?-sum:sum;
}
```