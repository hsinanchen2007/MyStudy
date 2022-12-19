
```
typedef struct tagNoDupStr {
	char* pStr; //组装最后的字符
	int  letterCnt; // 已经选出了字符个数
}NODUP_STR;

#define LETTER_MAX 27 

int combinedLetter(char* s, int* pletterCnt, int* pLetterUsed, int* pLetterChecked, int index, int strLen, int noDupLetterLen,
	NODUP_STR* pBaseStr, NODUP_STR* pCurStr)
{
	char curChar;
	int arrIndex;

	if (pBaseStr->letterCnt > 0 && pCurStr->letterCnt > 0 && strcmp(pCurStr->pStr, pBaseStr->pStr) > 0) {
		/* 不需要继续向下遍历了 */
		return 0;
	}

	if (index == strLen) {
		/* 遍历到最后了 可以判断最小字符串了 */
		if (pBaseStr->letterCnt == 0 || (pCurStr->letterCnt == noDupLetterLen && strcmp(pCurStr->pStr, pBaseStr->pStr) < 0)) {

			memcpy(pBaseStr->pStr, pCurStr->pStr, pCurStr->letterCnt); // 基础串没有先初始化
			pBaseStr->letterCnt = pCurStr->letterCnt;
		}
		return 0;
	}

	curChar = s[index];
	arrIndex = curChar - 'a';
	pLetterChecked[arrIndex]++;
	if (pLetterUsed[arrIndex] == 1) {
		/* 已经使用了该字符 */
		combinedLetter(s, pletterCnt, pLetterUsed, pLetterChecked, index + 1, strLen, noDupLetterLen, pBaseStr, pCurStr);
	}
	else {
		/* 没使用过 有两种选择是使用此字符 或不适用 */

		/*1: 使用*/
		pCurStr->pStr[pCurStr->letterCnt] = curChar;
		pCurStr->letterCnt++;
		pLetterUsed[arrIndex] = 1;
		combinedLetter(s, pletterCnt, pLetterUsed, pLetterChecked, index + 1, strLen, noDupLetterLen, pBaseStr, pCurStr);
		pLetterUsed[arrIndex] = 0; // 还原
		pCurStr->letterCnt--;
		pCurStr->pStr[pCurStr->letterCnt] = '\0';

		/*2：不使用 前提是有重复字符 */
		if (pletterCnt[arrIndex] > pLetterChecked[arrIndex] && ((strLen - index - 1) >= (noDupLetterLen - pCurStr->letterCnt))) {
			combinedLetter(s, pletterCnt, pLetterUsed, pLetterChecked, index + 1, strLen, noDupLetterLen, pBaseStr, pCurStr);
		}
	}

	pLetterChecked[arrIndex]--;

	return 0;
}


char* removeDuplicateLetters(char* s) {
	int   i;
	bool  haveDupLetter = false;
	int   strLen;
	int   noDupLetterCnt = 0;
	char* pFinalStr = NULL;
	int  letterCnt[LETTER_MAX] = { 0 };
	int  letterFlag[LETTER_MAX] = { 0 };
	int  checkLetterCnt[LETTER_MAX] = { 0 };
	NODUP_STR baseStr = { 0 };
	NODUP_STR newStr = { 0 };

	if (s == NULL) {
		return NULL;
	}
	strLen = strlen(s);
	for (i = 0; i < strLen; i++) {
		letterCnt[s[i] - 'a']++;
		if (letterCnt[s[i] - 'a'] > 1) {
			haveDupLetter = true;
		}
		else {
			noDupLetterCnt++;
		}
	}

	if (haveDupLetter == false) {
		return s; // 没有重复字符返回自己
	}

	baseStr.pStr = (char*)malloc(strLen + 1);
	memset(baseStr.pStr, 0, strLen + 1);
	newStr.pStr = (char*)malloc(strLen + 1);
	memset(newStr.pStr, 0, strLen + 1);
	combinedLetter(s, &letterCnt[0], &letterFlag[0], &checkLetterCnt[0], 0, strLen, noDupLetterCnt, &baseStr, &newStr);

	/*  找到了最小字符串 */
	if (baseStr.letterCnt > 0) {
		free(newStr.pStr);
		return baseStr.pStr;
	}

	free(baseStr.pStr);
	free(newStr.pStr);
	return NULL;
}
```
