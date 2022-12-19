### 解题思路
此处撰写解题思路

### 代码

```c
char * addBinary(char * a, char * b){
	char *p;
	if (strlen(b) > strlen(a))
	{
		p = a;
		a = b;
		b = p;
	}
	int size1 = strlen(a), size2 = strlen(b);
	if (size2 == 0)return a;
	int m = size1 - 1, n = size2 - 1;
	int i, j;
	int temp = 0;
	for (; m >= 0 && n >= 0; --m, --n)
	{
		i = *(a + m) - '0';
		j = *(b + n) - '0';
		if (i&&j)
		{
			if (temp == 1)
			{
				temp = 1;
				a[m] = '1';
			}
			else
			{
				temp = 1;
				a[m] = '0';
			}
		}
		else if (i || j)
		{
			if (temp == 1)
			{
				temp = 1;
				a[m] = '0';
			}
			else{
				temp = 0;
				a[m] = '1';
			}
		}
		else
		{
            a[m] = temp + '0';
			temp = 0;
		}
	}
	while (m >= 0)
	{
		i = *(a + m) - '0';
		if (i&&temp)
		{
			temp = 1;
			a[m] = '0';
		}
		else
		{
			a[m] = temp + i + '0';
			temp = 0;
		}
		--m;
	}
	if (temp == 1)
	{
		char *c = (char *)malloc((size1 + 2));
		for (i = size1 ; i > 0; --i)
			c[i] = a[i - 1];
		c[0] = '1';
		c[size1 + 1] = '\0';
		return c;
	}
	return a;
}
```