### 解题思路
此处撰写解题思路
注意两点：
1、字符串最后是以‘\0’结尾；
2、需考虑到strsSize等于0或1的情况；

### 代码

```c
char * longestCommonPrefix(char ** strs, int strsSize){
    if(!strsSize)
    {
        return "";
    }

    if(strsSize == 1)
    {
        return strs[0];
    }
    
    char *results = {""};
	char tmp_char;
	int min_length = strlen(strs[0]);
	int tmp_length = 0;
	int end_flag = 0;
	int i = 0, j = 0;

	if (min_length)
	{
		for (i = 1; i < strsSize; i++)
		{
			tmp_length = strlen(strs[i]);

			min_length = (tmp_length < min_length) ? tmp_length : min_length;
		}

		for (j = 0; j < min_length; j++)
		{
			tmp_char = strs[0][j];

			for (i = 1; i < strsSize; i++)
			{
				if (tmp_char != strs[i][j])
				{
					end_flag = 1;
					break;
				}
			}

			if (end_flag)
			{
				break;
			}
		}

		if (j)
		{
			results = (char *)malloc((j + 1) * sizeof(char));

			for (i = 0; i < j; i++)
			{
				results[i] = strs[0][i];
			}

            results[i] = '\0';
		}
	}
	
	return results;
}
```