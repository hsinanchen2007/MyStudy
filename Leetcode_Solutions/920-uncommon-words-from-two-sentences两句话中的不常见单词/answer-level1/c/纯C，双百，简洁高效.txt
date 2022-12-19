![1.png](https://pic.leetcode-cn.com/c4a2cbfd7db8807d3662becbd3060c83fd8c3ff96f2d61529a3381f19e72bdcf-1.png)

### 解题思路
1、先将A、B合并到res中；
2、将res排序；
3、列出只出现一次的单词。

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmq2(char**a, char**b){
	return strcmp(*a, *b);
}
char ** uncommonFromSentences(char * A, char * B, int* returnSize){
	if (!*A && !*B){
		*returnSize = 0;
		return 0;
	}
	char **res = (char**)malloc(sizeof(char*) * 100);
	int i = 0, j, k = 0, flag = 0;
	res[i] = strtok(A, " ");
	while (res[i])
		res[++i] = strtok(NULL, " ");
	res[i] = strtok(B, " ");
	while (res[i])
		res[++i] = strtok(NULL, " ");       //到此处第一步结束;
	qsort(res, i, sizeof(char*), cmq2);     //到此处第二步结束;
	for (j = 1; j < i; j++)
		if (strcmp(res[j], res[j - 1]) == 0){
			flag = 1;
		}
		else{
			if (flag == 0) 
				res[k++] = res[j - 1];
			else
				flag = 0;
		}	
    if (flag == 0) 
		res[k++] = res[j - 1];
	*returnSize = k;
	return res;
}
```