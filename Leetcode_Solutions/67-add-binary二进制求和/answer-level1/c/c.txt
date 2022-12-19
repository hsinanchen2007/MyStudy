### 解题思路
此处撰写解题思路
1、主要思想是二进制进位，其他没什么好说的；
2、一定要记住字符串结尾是'\0'；

### 代码

```c
char * addBinary(char * a, char * b){
    int size_a = strlen(a);
	int size_b = strlen(b);
	char *results;
	int max_size = (size_a > size_b) ? size_a : size_b;
	int cir_num = (size_a > size_b) ? size_b : size_a;
	int i;
	int add_flag = 0;

	results = (char *)malloc(sizeof(char) * (max_size + 2));

	//移位
	results++;

    results[max_size] = '\0';

	for (i = 1; i <= cir_num; i++)
	{
		results[max_size - i] = (a[size_a - i] - '0') + b[size_b - i] + add_flag;

		if (results[max_size - i] > '1')
		{
			results[max_size - i] -= 2;
			add_flag = 1;
		}
		else
		{
			add_flag = 0;
		}
	}

	if (size_a > size_b)
	{
		for (i = (max_size - cir_num - 1); i >= 0; i--)
		{
			results[i] = a[i] + add_flag;

			if (results[i] > '1')
			{
				results[i] -= 2;
				add_flag = 1;
			}
			else
			{
				add_flag = 0;
			}
		}
	}
	else if (size_a < size_b)
	{
		for (i = (max_size - cir_num - 1); i >= 0; i--)
		{
			results[i] = b[i] + add_flag;

			if (results[i] > '1')
			{
				results[i] -= 2;
				add_flag = 1;
			}
			else
			{
				add_flag = 0;
			}
		}
	}

	if (add_flag == 1)
	{
		results--;
		results[0] = '1';
	}

	return results;
}
```