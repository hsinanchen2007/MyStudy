### 解题思路
1. 首先，定义一个索引字符串的“指针”i，初始化i为0，同时定义返回整数的和out，初始化也为0；
2. 利用循环过滤掉空格，同时i前进；
3. 然后判断是否有正负号，有的话“指针”继续前进，若是负数还需另负数标志为1；
3. 这时判断当前位置i的字符是否为数字字符，是的话则表明可以得到一个整数，否则的话说明不能得到一个整数直接返回0；
4. 若第三步中当前位置i是一个字符，则进入下一个循环，循环继续的条件是当前位置的字符是一个数字字符，若是的话则执行out = out * 10 + str[i] - '0';
5. 退出循环后，若负数标志为1，返回当前数的相反数，否则返回当前数out。

### 代码

```c
int myAtoi(char* str) {
	double out = 0;
	int flagneg,i;
	i = flagneg = 0;
	while(str[i]==' ')
        i++;
    if(str[i]=='-')
    {
        flagneg = 1;
        i++;
    } 
    else if(str[i] == '+')
        i++;
    if(str[i]<'0' || str[i]>'9')
        return 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		out = out * 10 + str[i] - '0';
		if (out < INT_MIN || out > INT_MAX)
			break;
		i++;
	}
	if (flagneg)
	{
		out *= -1;
	}
	if (out > INT_MAX)
		return INT_MAX;
	if (out < INT_MIN)
		return INT_MIN;
	return out;
}
```