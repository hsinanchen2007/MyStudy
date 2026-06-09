### 解题思路
1、定义**result用来存储处理后的email地址
2、使用for循环，根据条件逐个地址进行处理（这个地方也可以用strtok直接根据@对email地址进行分割）
3、对result进行快排
4、遍历result统计不一样的email地址个数

### 代码

```c

int cmp(const void *a, const void *b)
{
	return strcmp(*(char*const*)a, *(char*const*)b);
}

int numUniqueEmails(char ** emails, int emailsSize)
{
	char **result = (char**)malloc(sizeof(char*) * 100);
	memset(result, 0, sizeof(char*)*100);
	int i = 0, j = 0, ret = 0;
	
	for ( i = 0; i < emailsSize; i++) 
	{
		int isA = 0, k = 0;
		int emailLen = strlen(emails[i]);
		result[i] = (char*)malloc(sizeof(char) * 102);
		memset(result[i], 0, 102);
		for ( j = 0; j < emailLen; j++) 
		{
			if(emails[i][j] == '@') // 如果检测到@,则全部追加到字符串后面
			{
				isA = 1;
				while(j < emailLen)
				{
					//emails[i][k++] = emails[i][j++];
					result[i][k++] = emails[i][j++];
				}
			}
			else if(emails[i][j] == '.' && isA == 0) // 如果在@之前检测到'.'，则忽略点
			{
			}
			else if(emails[i][j] == '+') // 如果检测到+，则跳转到@
			{
				while(emails[i][j] != '@')
				{
					j++;
				}
				j--;
			}
			else
			{
				//if(j > k)
				//emails[i][k] = emails[i][j];
				result[i][k] = emails[i][j];
				k++;
			}
		}
		//emails[i][k] = '\0';
		result[i][k] = '\0';
	}
	qsort(result, emailsSize, sizeof(char*), cmp);
	
	ret = 1;
	for(i = 1; i < emailsSize; i++)
	{
		if(strcmp(result[i], result[i-1]) == 0)
		{
			continue;
		}
		else
		ret++;
		
	}
	return ret;

}
```