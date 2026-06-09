```
#include <stdio.h>
#include <string.h>

#define MAX_S 512
#define MAX_WORDS 50

static int flag[MAX_S] = { 0 };
static char result[MAX_S * 5] = { 0 };

static void GetSubStr(const char *s, const char *word)
{
	int sLen, wLen;
	int pos;
	int i = 0, offset = 0;
	char *p;

	sLen = strlen(s);
	wLen = strlen(word);

	while (offset <= (sLen - wLen)) {
		p = strstr(s + offset, word);
		if (!p) {
			break;
		}

		offset = p - s;

		for (i = offset; i < offset + wLen; i++) {
			flag[i]++;
		}
		offset ++;
	}
}

static void GetFlags(char ** words, int wordsSize, char *s)
{
	int i;

	for (i = 0; i < wordsSize; i++) {
		GetSubStr(s, words[i]);
	}
}

static char * GetAns(char *s)
{
	int i, j = 0;
	int sLen = strlen(s);
	int pre0 = 1, pre1 = 0;

	for (i = 0; i < sLen; i++) {
		/* 如果大于零，表明有数字覆盖过，如果前边是0，则表明加粗开始 */
		if (flag[i] > 0) {
			if (pre0) {
				strcat(&result[j], "<b>");
				j += 3;
				pre0 = 0;
			}
			pre1 = 1;
		} else {
			/* flag是0，前边是1，表明加粗结束 */
			if (pre1 == 1) {
				strcat(&result[j], "</b>");
				j += 4;
				pre1 = 0;
			}
			pre0 = 1;

		}
		result[j] = s[i];
		j++;
	}

	/* 结束的时候，如果前边是大于零，则表明字符加粗结束 */
	if (pre1 == 1) {
		strcat(&result[j], "</b>");
	}

	return result;
}

char * boldWords(char ** words, int wordsSize, char * S)
{
	memset(flag, 0, sizeof(flag));
	memset(result, 0, sizeof(result));

	GetFlags(words, wordsSize, S);

	return GetAns(S);
}
```
