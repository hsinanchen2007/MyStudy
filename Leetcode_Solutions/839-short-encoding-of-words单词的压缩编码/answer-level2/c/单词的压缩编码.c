### 解题思路
使用一个标记数组，标记出不属于其他单词的后缀，但是时间复杂度很高，
### 代码

```c
bool match(char* s1, char* s2) {
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	int i = len1 - 1, j = len2 - 1;
	while (i > -1 && j > -1) {
		if (s1[i--] != s2[j--]) return false;
	}
	return true;
}
int minimumLengthEncoding(char ** words, int wordsSize) {
	char *mark = (char*)malloc(sizeof(char)*wordsSize);
	memset(mark, 0, sizeof(char)*wordsSize);
	int res = 0;
	int i, j;
	for (i = 0; i < wordsSize; i++) {
		for (j = 0; j < i; j++) {
			if (mark[j]) {
				if (match(words[i], words[j])) {
					if (strlen(words[i]) > strlen(words[j])) {
						mark[j] = 0;
						mark[i] = 1;
						res = res - strlen(words[j]) + strlen(words[i]);
					}
					break;
				}
			}
		}
		if (i == j) {
			mark[i] = 1;
			res = res + strlen(words[i]) + 1;
		}
	}
	return res;
}
```