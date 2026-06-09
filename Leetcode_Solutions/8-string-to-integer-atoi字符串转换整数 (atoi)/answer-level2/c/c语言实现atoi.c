### 解题思路
此处撰写解题思路
编写的时候用了很长事件调试，while(*str++ == '')这种方式会直接跳过第一个数字，if (num != (int)num)这个判断是参考别人的题解，但是如果是float类型的num就会失败，后来看到有一个人跟我同样的错误，所以改为
double类型的就可以通过。这个问题我也没有搞清楚是什么原因

### 代码

```c
int myAtoi(char * str){
		int flag = 1;
	double num = 0;
	while ((*str) == ' ')
	{
		str++;
	}
	if (*str == '-') {
		flag = -1;
	}
	if (*str == '-' || *str == '+')
	{
		str++;
	}
	while ((*str >= '0') && (*str <= '9'))
	{
		num = (num * 10) + (*str - '0');
		if (num != (int)num) {//溢出判断
			return flag == 1 ? INT_MAX : INT_MIN;
		}
			str++;
	}
	num *= flag;
	return num;
}
```