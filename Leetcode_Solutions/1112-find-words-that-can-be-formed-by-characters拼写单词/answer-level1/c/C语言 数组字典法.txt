### 解题思路
额外申请两个数组，用以存放chars数组的结果，因为是小写字母，所以数组空间26就够了。
申请两个原因是在轮询过程中，其中一个数组的值会因计算次数而被清空，需要重新赋值。

### 代码

```c
#include <stdlib.h>

int countCharacters(char ** words, int wordsSize, char * chars) {
	if (words == NULL || wordsSize == 0 || chars == NULL) {
		return 0;
	}
	int alphaA[26];
	int alphaB[26];
	memset(alphaA, 0, sizeof(int) * 26);
	memset(alphaB, 0, sizeof(int) * 26);
	for (int i = 0; i < strlen(chars); ++i) {
		if (chars[i] >= 'a' && chars[i] <= 'z') {
			alphaA[chars[i] - 'a']++;
		}
		else {
			continue;
		}
	}
	memcpy(alphaB, alphaA, sizeof(int) * 26);
	int wordLens = 0;
	int rtnLens = 0;
	int countJ = 0;
	for (int i = 0; i < wordsSize; ++i) {
		wordLens = strlen(words[i]);
		memcpy(alphaB, alphaA, sizeof(int) * 26);
		countJ = 0;
		for (int j = 0; j < wordLens; ++j) {
            if (words[i][j] - 'a' < 0 || words[i][j] - 'a' > 26){
                break;
            }
			if (alphaB[words[i][j] - 'a'] > 0) {
				alphaB[words[i][j] - 'a']--;
				countJ++;
			}
			else {
				break;
			}
		}
		if (countJ == wordLens) {
			rtnLens += wordLens;
		}
	}
	return rtnLens;
}
```