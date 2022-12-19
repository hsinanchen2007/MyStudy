### 解题思路


### 代码

```c
/*int** indexPairs(char * text, char ** words, int wordsSize, int* returnSize, int** returnColumnSizes){
    int len = strlen(text);
    if (len < 1 || len > 100 || wordsSize < 1 || wordsSize > 20) {
        return NULL;
    }
    for (int i = 0; i < wordsSize; i++) {
        if (strlen(words[i]) < 1 || strlen(words[i]) > 50) {
            return NULL;
        }
    }
    int res[2000][2] = {0};
    int s = 0;
    
    for (int i = 0; i < wordsSize; i++) {
        for (int j = 0; j < strlen(words[i]); j++) {
            for (int k = 0; k < len; k++) {
                if (words[i][j] == text[k]) {
                    res[s][0] = k;
                    res[s][1] = k + strlen(words[i]);
                    s++;
                }
            }
        }
    }
    *returnSize = s - 1;
    **returnColumnSizes = 2;
    return res;
}
*/
    
int cmp (const void *a, const void *b) {  //二维数组的比较
	int *ap = *(int**)a;
	int *bp = *(int**)b;
	if (ap[0] == bp[0]) {
		return ap[1] - bp[1];
	} else {
		return ap[0] - bp[0];
	}
}
int** indexPairs(char * text, char ** words, int wordsSize, int* returnSize, int** returnColumnSizes)
{
	int lent = strlen(text);
    int **res = (int**)malloc(sizeof(int*) * 1000);
    int cnt = 0;
	for (int i = 0; i < wordsSize; i++) {
		int len = strlen(words[i]);
		if (len > lent) {
			continue;
		}
		for (int j = 0; j < lent-len+1; j++) {  //这里要注意j的取值范围
			if (strncmp(text+j, words[i], len) == 0) {
				res[cnt] = (int*)malloc(sizeof(int) * 2);
				res[cnt][0] = j;
				res[cnt][1] = j + len-1;   //这里要注意j + len-1 而不是j + len
				cnt++;
			}
		}
	}
	qsort(res, cnt, sizeof(res[0]), cmp);
	*returnSize = cnt;
	returnColumnSizes[0] = (int*)malloc(sizeof(int) * cnt);   //returnColumnSizes可以看成是一个一行cnt列的二维数组。
	for (int i = 0; i < cnt; i++) {
		returnColumnSizes[0][i] = 2;
	}
	return res;
}
```