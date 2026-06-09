### 解题思路
此处撰写解题思路
用的很一般的方法--将第一个字符串作为参照串然后一一和剩余字符串比较，找出最小的num，然后一开始给返回字符串赋值的时候想用string类型的，后来发现c中没有，就老老实实用了循环。一开始判断的等于写成了不等于，找了20分钟的错qaq
### 代码

```c
char * longestCommonPrefix(char ** strs, int strsSize) {
    if(strsSize==0)
    return "";
	int i = 1, j = 0, num = strlen(strs[0]), n ;
	char *str;
	while (i < strsSize)
	{
		j = 0;
		while (strs[0][j] == strs[i][j] && strs[0][j] != '\0')
		{
			j++;
		}
		if (num > j)
		{
			num = j;
		}
		i++;
	}
	str = (char*)malloc(sizeof(char)*(num + 1));
	for (n = 0;n < num;n++)
	{
		str[n] = strs[0][n];
	}
	str[n] = '\0';
	return str;
}
```