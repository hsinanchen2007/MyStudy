### 解题思路
只要好好仔细讨论就可以

### 代码

```c
int myAtoi(char * str)
{
    int  i = 0;
	int length = strlen(str);
	if(length == 0)
		return 0;
    for(i = 0; str[i] == 32 && i < length; i++);
    char sign = '+';
    long num = 0;
    if((str[i] == '+' || str[i] == '-') && i < length)
    {
        sign = str[i];
        i++;
        if((str[i] < '0' || str[i] > '9') && i < length)
        return 0;
    }
    else if(str[i] >= '0' && str[i] <= '9' && i < length);
    else
    return 0;
    while(str[i] >= '0' && str[i] <= '9' && i < length)
    {
        num = num * 10 + (str[i] - '0');
        if(num >= 2147483648 && sign == '-' && i < length)
        return -2147483648;
        if(num >= 2147483647 && sign == '+' && i < length)
        return 2147483647;
        i++;
    }
    if(sign == '-')
    return (int)(-num);
    else
    return (int)num;
}

```