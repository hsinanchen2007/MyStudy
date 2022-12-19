### 解题思路
首先判断字符串是否为空；
构建新字符串数组，该数组保留每次发现的无重复字符的字符串，并用count保存最长的字符串数组的长度。
每次发现有重复字符，将够贱的字符串数组清空，重新开始。

### 代码

```c
int lengthOfLongestSubstring(char * s){
int i, j,len,k,count,flag,t,m;
	k = 0;	
	flag = 0;
	len = strlen(s);//字符串长度
	char* mark = (char*)malloc(sizeof(char) *(2*len+3));
		
	mark[0] = s[0];
	mark[len] = '\0';
	if (len != 0)
	{
		count = 1;
		for (i = 1; i < len; i++)
		{
			
			if (s[i] == mark[k])
			{
				if (k+1 > count)
				{
					count = k+1;
				}
				k = 0;
				strcpy(mark, "");//字符串清零
				mark[k] = s[i];
			}
			else
			{
				//保存一个字母			
				for (j = 0; j <= k; j++)
				{
					if (s[i] == mark[j])
					{
						flag = 1; //字符串发生重复的标志
						if (k >= count)
						{
							count = k + 1;
						}
						strcpy(mark, "");//字符串清零
						m = k - j;
						for (t = 0; t <m; t++)
						{
							j = j + 1;
							mark[t] = mark[j];//串味

						}
						k = m;
						mark[k] = s[i]; 
						break;
					}
				}

				if (!flag)
				{
					k = k + 1;
					mark[k] = s[i]; 
					if ((s[i + 1] == '\0')&&(k+1>count))
					{
						count = k + 1;
					}
				}
				flag = 0;
			}

		}
	}
	else {
		count = 0;
	}

return count;
}
```