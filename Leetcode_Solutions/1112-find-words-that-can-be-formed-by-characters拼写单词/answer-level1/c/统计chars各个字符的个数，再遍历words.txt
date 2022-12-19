### 解题思路
1、for循环，将chars中各个字符的个数记录到table1[26]中
2、for循环遍历words，首先判断长度，如果word的长度>chars长度，则直接跳过；否则，拷贝table1到table2中，然后遍历word，遇到字符直接在table2中减一。直至循环结束或者table2中某个字符减到<0

### 代码

```c
int countCharacters(char ** words, int wordsSize, char * chars)
{
	int ret = 0;
	int len = strlen(chars);
	char table1[26] = {0}; // 用来统计各个字符的个数
	char table2[26] = {0}; // 用来备份table1
	int i = 0, j = 0, k = 0;
	for ( i = 0; i < len; i++) // 统计chars中各个字符的个数
	{
		table1[chars[i]-'a']++;
	}

	for ( i = 0; i < wordsSize; i++) 
	{
		int wordLen = strlen(words[i]);
		if(wordLen > len)  // 如果word的长度>chars的长度，则直接进行下个word的判断
		{
			continue;
		}
		memcpy(table2, table1, 26);
		for ( j = 0; j < wordLen; j++) 
		{
			if(table2[words[i][j]-'a']-- <= 0)
            {
                break;
            }            
		}
		if(j == wordLen)
		{
			ret += wordLen;
		}
	}

	return ret;
}

```