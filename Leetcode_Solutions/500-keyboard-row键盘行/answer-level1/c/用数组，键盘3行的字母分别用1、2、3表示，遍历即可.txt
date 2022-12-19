### 解题思路
1、将每个字母根据其所在行分别置为1/2/3
2、遍历words，不再同一行，则进入下一个单次遍历

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** findWords(char ** words, int wordsSize, int* returnSize){
	char r1[] = "qwertyuiop";
	char r2[] = "asdfghjkl";
	char r3[] = "zxcvbnm";
	char table[130] = {0};
	int i = 0;
	for ( i = 0; i < 10; i++) 
	{
		table[r1[i]] = 1;
		table[r1[i]-32] = 1;
	}
	for ( i = 0; i < 9; i++) 
	{
		table[r2[i]] = 2;
		table[r2[i]-32] = 2;
	}
	for ( i = 0; i < 7; i++) 
	{
		table[r3[i]] = 3;
		table[r3[i]-32] = 3;
	}

	char **ret = (char**)malloc(sizeof(char*) * wordsSize);
	for ( i = 0; i < wordsSize; i++) 
	{
		ret[i] = (char*)malloc(sizeof(char)*100);
		memset(ret[i], 0, 100);
	}
	int j = 0, count = 0;
	int flag = 0;
	for ( i = 0; i < wordsSize; i++) 
	{
		flag = 0;
		for ( j = 0; j < strlen(words[i]); j++) 
		{
			if(table[words[i][j]] != table[words[i][0]])
			{
				flag = 1;
				break;
			}
		}
		if(!flag)
		{
			memcpy(ret[count++], words[i], strlen(words[i]));
		}
	}
	*returnSize = count;

	return ret;

}
```