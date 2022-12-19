### 解题思路
将一个单词的pattern转化为数组的数字：从cnt=0开始标识每个位置，和以前都不同的字母位置用cnt++表示，和以前相同的数字用一样的数字标识。这样把每个单词的pattern就直观表示出来啦！
### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <string.h>

char ** findAndReplacePattern(char ** words, int wordsSize, char * pattern, int* returnSize){
	int len = strlen(pattern);
	int i, j, k;
	int diff = 0;
	int flag;
	int patt[22];
	patt[0] = diff;
	for (i = 1; i < len; i++) {
		flag = 1;
		for (j = (i - 1); j >= 0; j--) {
			if (pattern[i] == pattern[j]) {
				patt[i] = patt[j];
				flag = 0;
				break;
			}
		}
		if (flag) {
			diff++;
			patt[i] = diff;
		}
	}
	int index[50];
	int tmp[22];
	int cnt = 0;
	for (i = 0; i < wordsSize; i++) {
		diff = 0;
		flag = 1;
		tmp[0] = diff;
		for (j = 1; j < len; j++) {
			flag = 1;
			for (k = (j - 1); k >= 0; k--) {
				if (words[i][k] == words[i][j]) {
					tmp[j] = tmp[k];
					flag = 0;
					break;
				}
			}
			if (flag) {
				diff++;
				tmp[j] = diff; 
			}
		}
		flag = 0;
		for (j = 0; j < len; j++) {
			if (tmp[j] != patt[j]) {
				flag = 1;
			}
		}
		if (flag)  continue;
		index[cnt++] = i;
	}
	char **ans = (char **)malloc(sizeof(char *) * 55);
	for (i = 0; i < cnt; i++) {
		ans[i] = (char *)malloc(sizeof(char)*22);
		strcpy(ans[i], words[index[i]]);
	}
	*returnSize = cnt;
	return ans;
}
```