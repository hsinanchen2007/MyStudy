### 

![image.png](https://pic.leetcode-cn.com/b28f57710ff41642bb5cf9fcf6b5c1d2b137d769ce69a192150555c91cdac069-image.png)

### 代码

```c

typedef struct dotPos {
	char* dotpos[3]; //记录每个分割点的指针地址
	struct dotPos *next;
}DOT_POS;

int AnalysisDotPos(char *pStr, int dotLeftCnt, DOT_POS *pHead, int *pIpCount)
{
	char* pChar = pStr;
	char ch;
	if (dotLeftCnt == 0) { // 递归结束条件，当分割点用完后判断后面的字符串是否满足ip地址数值
		if (pStr[0] == '\0') {
			return false;
		}

		if (atoi(pStr) > 255) {
			return false;
		}

		if (strlen(pStr) > 3) {
			return false;
		}
		
		if (pStr[0] == '0' && pStr[1] != '\0') {
			return false;
		}

		//满足情况下记录下此IP地址分割点地址信息
		DOT_POS *pIpDotPos = (DOT_POS *)malloc(sizeof(DOT_POS));
		memcpy(pIpDotPos->dotpos, pHead->dotpos, sizeof(pHead->dotpos));
		pIpDotPos->next = pHead->next;
		pHead->next = pIpDotPos;
		*pIpCount += 1;
		return true;
	}

	//如果解析的第一个字符就是0 就不用遍历了直接使用此字符作为一个分割点数值
	if (*pChar == '0') {
		pHead->dotpos[3 - dotLeftCnt] = pChar + 1;
		AnalysisDotPos(pChar + 1, dotLeftCnt - 1, pHead, pIpCount);
		return true;
	}

	//遍历字符所有满足分割字符情况
	while (*pChar != '\0') {
		ch = *(pChar + 1);
		*(pChar + 1) = '\0';
		if (atoi(pStr) <= 255) {
			*(pChar + 1) = ch;
			pHead->dotpos[3 - dotLeftCnt] = pChar + 1;
			AnalysisDotPos(pChar + 1, dotLeftCnt - 1, pHead, pIpCount);
		}
		else {
			*(pChar + 1) = ch;
			break;
		}

		*(pChar + 1) = ch;
		pChar++;
	}

	return true;
}


/**25525511135
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** restoreIpAddresses(char* s, int* returnSize) {
	int count = 0;
	DOT_POS head = { 0 };
	int len = 0;

	if (s == NULL) {
		*returnSize = 0;
		return NULL;
	}
	len = strlen(s);
	char* pTmpStr = (char *)malloc(len + 1);
	pTmpStr[len] = '\0';
	memcpy(pTmpStr, s, len);
	AnalysisDotPos(pTmpStr, 3, &head, &count);

	if (count == 0) {
		free(pTmpStr);
		*returnSize = 0;
		return NULL;
	}

	// 根据记录下来的所有ip地址分割点地址，构造最终输出的ip地址字符串
	char** pRslt = (char**)malloc(count * sizeof(char*));
	DOT_POS* pNode = head.next;
	DOT_POS* pTmpNode = head.next;
	char* pTmp = NULL;
	int i = 0;
	while (pNode != NULL) {
		pTmpNode = pNode;
		char* pStr = (char *)malloc(len + 4);
		pRslt[i++] = pStr;

		//根据分割点地址偏移算出所有分割符的位置
		int dotpos1 = pNode->dotpos[0] - pTmpStr;
		int dotpos2 = pNode->dotpos[1] - pTmpStr;
		int dotpos3 = pNode->dotpos[2] - pTmpStr;
		pStr[len + 3] = '\0';
		pTmp = pStr;
		memcpy(pTmp, s, dotpos1);
		pTmp += dotpos1;
		*pTmp = '.';
		pTmp += 1;
		memcpy(pTmp, s + dotpos1, dotpos2 - dotpos1);
		pTmp += (dotpos2 - dotpos1);
		*pTmp = '.';
		pTmp += 1;
		memcpy(pTmp, s + dotpos2, dotpos3 - dotpos2);
		pTmp += (dotpos3 - dotpos2);
		*pTmp = '.';
		pTmp += 1;
		memcpy(pTmp, s + dotpos3, len - dotpos3);

		pNode = pNode->next;
		free(pTmpNode);
	}
	free(pTmpStr);
	*returnSize = count;
	return pRslt;
}


```