### 解题思路

其实就是先找字符'e'，如果只找到一个'e'的话它前面，后面都应该是有效数字，如果找不到e的话就判断整个字符串是不是有效数字。
判断字符串是不是有效数字就加条件，比如只能有一个'+'/'-', 只能有一个小数点等。几个条件都满足了就是有效数字。

### 代码

```c
int isNumberWithoutE(char* s, int head, int tail, int *dotnum)
{
	int i, num = 0, plus = -1, minus = -1, dot = -1;
	for (i = head; i <= tail; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			num++;
			continue;
		}
		if (s[i] == '.')
		{
			if (dot != -1)
				return 0;
			dot = i;
			continue;
		}
		if (s[i] == '+')
		{
			if (plus != -1)
				return 0;
			plus = i;
			continue;
		}
		if (s[i] == '-')
		{
			if (minus != -1)
				return 0;
			minus = i;
			continue;
		}
		return 0;
	}
	if (num == 0)
		return 0;

	// both + and -?
	if (plus >= 0 && minus >= 0)
		return 0;

	// + and - should be in head
	if (plus >= 0 && plus != head)
		return 0;
	if (minus >= 0 && minus != head)
		return 0;
	*dotnum = dot;
	return 1;
}

bool isNumber(char * s){
	// Remove extra space
	int head, tail, i, e = -1, dot, ret;
	head = 0;
	tail = strlen(s) - 1;
	while (head <= tail)
	{
		if (s[head] == ' ')
			head++;
		else
			break;
	}
	while (head <= tail)
	{
		if (s[tail] == ' ')
			tail--;
		else
			break;
	}
	if (head > tail)
		return 0;

	// Look for e
	for (i = head; i <= tail; i++)
	{
		if (s[i] == 'e')
		{
			// Two or more e?
			if (e >= 0)
				return 0;
			e = i;
		}
	}
	if (e == -1)
		return isNumberWithoutE(s, head, tail, &dot);
	if (e == head || e == tail)
		return 0;
	ret = isNumberWithoutE(s, head, e - 1, &dot);
	if (!ret)
		return ret;
	ret = isNumberWithoutE(s, e + 1, tail, &dot);
	return ret && (dot == -1);
}
```