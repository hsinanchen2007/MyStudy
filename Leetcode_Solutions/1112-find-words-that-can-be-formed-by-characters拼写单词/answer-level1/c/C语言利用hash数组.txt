### 解题思路
利用26个hash数组，很方便的就知道是否满足。具体见代码。

### 代码

```c
#define MAXLEN 26

int countCharacters(char ** words, int wordsSize, char * chars)
{
	if (words == NULL || chars == NULL) {
		return 0;
	}
	
	int origin[MAXLEN];
	int substr[MAXLEN];
	bool flag = 0;
	int count = 0;

	memset(substr, 0, sizeof(int) * MAXLEN);
	for (int i = 0; i < strlen(chars); i++) {
		substr[chars[i] - 'a']++;
	}
	
	for (int i = 0; i < wordsSize; i++) {
		flag = 0;
		memset(origin, 0, sizeof(int) * MAXLEN);
		for (int j = 0; j < strlen(words[i]); j++) {
			origin[words[i][j] - 'a']++;
		}
		
		for (int k = 0; k < MAXLEN; k++) {
			if (substr[k] < origin[k]) {
				flag = 1;
				break;
			}
		}
		if (!flag) {
			count += strlen(words[i]);
		}
	}
	return count;
}
```