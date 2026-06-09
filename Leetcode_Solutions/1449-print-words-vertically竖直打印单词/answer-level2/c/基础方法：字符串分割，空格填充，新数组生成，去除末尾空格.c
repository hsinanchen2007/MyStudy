### 解题思路
1、用strtok将字符串根据空格进行分割，结果存入temp中，同时记录单词个数rows（结果的最长单词长度）和最长单词长度cols（结果的单词个数）
2、根据rows循环对temp中的单词末尾填充空格，保证每个单次的长度均为cols
3、双层for循环将temp旋转读取到ret中
4、对ret中的元素循环遍历，去除末尾的空格

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** printVertically(char * s, int* returnSize){
	char **ret = (char**)malloc(sizeof(char*)*201);
	char temp[201][202] = {0}; // 用来存放原字符串根据空格分割成的数组

	int i = 0, j = 0;
	int rows = 0, cols = 0;  // rows为原始行（新列），cols为原始列（新行）

	char *p = strtok(s, " ");
	while(p != NULL) // 根据空格分割字符串，并存入temp中
	{
		strcpy(temp[rows++], p);
		cols = cols > strlen(p) ? cols : strlen(p); // 计算出最大长度，即新数组的元素个数
		p = strtok(NULL, " ");
	}
    
	for ( i = 0; i < cols; i++) 
	{
		ret[i] = (char*)malloc(sizeof(char) * (rows+3));
		memset(ret[i], 0, (rows+3));
	}
    
	for(i = 0; i < rows; i++) // 为每个单次填充空格
	{
		while(strlen(temp[i]) < cols)
		{
			temp[i][strlen(temp[i])] = ' ';
		}
	}
	for ( i = 0; i < cols; i++)  // 生成新的数组
	{
		for ( j = 0; j < rows; j++) 
		{
			ret[i][j] = temp[j][i];
		}
	}
	for(i = 0; i < cols; i++) // 去除末尾空格
	{
		while(ret[i][strlen(ret[i])-1] == ' ')
		{
			ret[i][strlen(ret[i])-1] = '\0';
		}
	}
    
    *returnSize = cols;
	return ret;


}
```