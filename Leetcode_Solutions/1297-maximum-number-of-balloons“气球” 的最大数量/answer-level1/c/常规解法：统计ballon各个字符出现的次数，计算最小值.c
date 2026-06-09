### 解题思路
1、for循环遍历统计个字符出现的次数（可以使用switch只统计balon这5个字符的次数，也可以根据下标用数组统计所有字符的个数）
2、将```l```和```o```的次数折半
3、找出'b','a','l','o','n'次数的最小值即可。

### 代码

```c
int maxNumberOfBalloons(char * text)
{
    	int i = 0;
	int len = strlen(text);
	int table[15] = {0};
	for ( i = 0; i < len; i++) 
	{
		if(text[i] < 'p')
		table[text[i]-'a']++;
		
	}
	table[14] /= 2;  // 'o'
	table[11] /= 2;  // 'l'

	int ret = table[0]; // 'a'
	ret = ret <= table[1] ? ret : table[1]; // 'b'
	ret = ret <= table[11] ? ret : table[11]; // 'l'
	ret = ret <= table[13] ? ret : table[13]; // 'n'
	ret = ret <= table[14] ? ret : table[14]; // 'o'
	
	return ret;

}

/*
{
	int i = 0;
	int len = strlen(text);
	int table[5] = {0};
	for ( i = 0; i < len; i++) 
	{
		switch(text[i])
		{
			case 'a':
				table[0]++;
				break;
			case 'b':
				table[1]++;
				break;
			case 'l':
				table[2]++;
				break;
			case 'o':
				table[3]++;
				break;
			case 'n':
				table[4]++;
				break;
		}
	}
	table[2] /= 2;
	table[3] /= 2;

	int ret = table[0];
	for ( i = 1; i < 5; i++) 
	{
		if(table[i] < ret)
		{
			ret = table[i];
		}
	}
	return ret;
}
*/
```