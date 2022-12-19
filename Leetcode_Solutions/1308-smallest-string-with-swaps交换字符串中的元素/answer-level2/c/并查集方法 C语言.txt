### 解题思路
1. 可交换的ID用并查集找出来；
2. 将所有可交换的字符按father ID存到数组中，qsort之；
3. 维护一组ID，表示输出过程中已经使用到的元素ID；
3. 填写返回数组过程：遍历s,找到当前字符的father ID对应的qsort之后的数组，从头到尾取元素；


【这题低空飞过，占用太多内存，时间复杂度是n^2 *logn。。。】

### 代码

```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_A_LEN 100000

int parent[MAX_A_LEN] = {0};
char **tmpArray;
int curALen[MAX_A_LEN] = {0};
int curUsedTmp[MAX_A_LEN] = {0};
int fiLen[MAX_A_LEN] = {0};

void InitG(void)
{	
	memset(parent, 0, sizeof(int) * MAX_A_LEN);	
	memset(curALen, 0, sizeof(curALen));
	memset(curUsedTmp, 0, sizeof(int) * MAX_A_LEN);
	memset(fiLen, 0, sizeof(fiLen));
	return;
}

void UnionInit(void)
{
	int i;
	for (i = 0; i < MAX_A_LEN; i++) {
		parent[i] = i;
	}
}

int Find(int x)
{
	while (parent[x] != x) {
		parent[x] = parent[parent[x]];
		x = parent[x];
	}
	return x;
}

void Union(int fa, int fb)
{
	if (fa < fb) {
		parent[fb] = fa;
		return;
	}
	parent[fa] = fb; 	
}

void ParsePairs(char *s, int **pairs, int pairsSize)
{
	int i;
	int fa;
	int fb;
	for (i = 0; i < pairsSize; i++) {
		fa = Find(pairs[i][0]);
		fb = Find(pairs[i][1]);
		if (fa != fb) {
			Union(fa, fb);
		}		
	}
}

int cmp(const void *a, const void *b)
{
	return (*(char*)a) - (*(char*)b);
}

void fiInfoCalc(char *s)
{
	int i;
	int sLen;
	int fi;
		
	tmpArray = (char**)malloc(sizeof(char*) * MAX_A_LEN);
	sLen = strlen(s);
	for (i = 0; i < sLen; i++) {
		fi = Find(i);
		fiLen[fi] += 1;
	}
	
	for (i = 0; i < MAX_A_LEN; i++) {
		tmpArray[i] = (char*)malloc(sizeof(char) * fiLen[i]);
		memset(tmpArray[i], 0, sizeof(char) * fiLen[i]);
	}
}

void ParentSort(char *s)
{
	int i;
	int fi;
	int j;
	int sLen;
	
	sLen = strlen(s);
	for (i = 0; i < sLen; i++) {
		fi = Find(i);
		tmpArray[fi][curALen[fi]++] = s[i];				
	}
	
	for (i = 0; i < sLen; i++) {
		qsort(tmpArray[i], curALen[i], sizeof(char), cmp);
	}
	return;
}

void TransS(char *s, char *result)
{
	int i;
	int sLen;
	int fi;
	
	sLen = strlen(s);
	for (i = 0; i < sLen; i++) {
		fi = Find(i);
		result[i] = tmpArray[fi][curUsedTmp[fi]++];
	}
	result[i] = '\0';	
}

char * smallestStringWithSwaps(char * s, int** pairs, int pairsSize, int* pairsColSize)
{
	char *result;
	int sLen;
	
	sLen = strlen(s);
	result = (char*)malloc(sLen + 1);
	InitG();
	UnionInit();
	ParsePairs(s, pairs, pairsSize);
	fiInfoCalc(s);
	ParentSort(s);
	TransS(s, result);
	free(tmpArray);
	return result;	
}
```