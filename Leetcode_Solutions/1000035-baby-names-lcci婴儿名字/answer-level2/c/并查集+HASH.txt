### 解题思路
核心思想是并查集，中间造了无数个轮子。



### 代码

```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define HASH_VOLUM    400000000
typedef struct {
	int index;
	char *name;
	struct HashNode *next;
}HashNode;

typedef struct {
	int val;
	char name[1000];
}NameStr;

int *parent;
NameStr *nameList;
int parentHashId[4096];
//HashNode nameParsedTable[4096];

void ParseName(char *names, char *nameParsed, int *num)
{
	int i;
	int strLenth;
	int curNameParsedLen;
	
	curNameParsedLen = 0;
	*num = 1;
	strLenth = strlen(names);
	for (i = 0; i < strLenth; i++) {
		if (names[i] == '(') {
			nameParsed[curNameParsedLen] = '\0';
			break;
		}
		nameParsed[curNameParsedLen++] = names[i];
	}
	i++;
	(*num) = names[i] - '0';
	i++;
	while(names[i] != ')') {
		(*num) = (*num) * 10 + names[i] - '0';
		i++;
	}
}

void ParseSameName(char *sameNameStr, char *nameA, char *nameB)
{
	int i;
	int curNameLen;
	int sameNameLen;
	
	curNameLen = 0;
	sameNameLen = strlen(sameNameStr);
	for (i = 1; i < sameNameLen; i++) {
		if (sameNameStr[i] == ',') {
			break;
		}
		nameA[curNameLen++] = sameNameStr[i];
	}
	nameA[curNameLen] = '\0';
	curNameLen = 0;
	i++;
	while (sameNameStr[i] != ')') {
		nameB[curNameLen++] = sameNameStr[i];
		i++;
	}
	nameB[curNameLen] = '\0';
	return;	
}

unsigned int APHash(char *str)
{
	int i;
	unsigned int hashId = 0;
	
	for (i = 0; *str; i++) {
		if ((i & 1) == 0) {
			hashId ^= (hashId << 7) ^ (*str++) ^ (hashId >> 3);
		} else {
			hashId ^= (hashId << 11) ^ (*str++) ^ (hashId >> 5); 
		}
	}
	return hashId % HASH_VOLUM;	
}

unsigned BKDRHash(char *str) 
{
	unsigned int hashId = 0;
	unsigned int seed = 131313131;
	while (*str) {
		hashId = hashId * seed + (*str++);
	}
	return hashId % HASH_VOLUM;
}

unsigned int HASH(char *str)
{
	char *strTmp;
	strTmp = (char*)malloc(sizeof(char) * (strlen(str) + 1));
	memcpy(strTmp, str, (strlen(str) + 1));
	unsigned int hashId;
	hashId = (APHash(strTmp) + BKDRHash(str)) / 2;
	return hashId;
}

int Find(int x)
{
	while (parent[x] != x) {
		x = parent[x];
	}
	return x;
}
int FindFather(int x, int y) 
{
	char nameX[1000];
	char nameY[1000];
	int xLen;
	int yLen;
	int fatherId;
	
	memcpy(nameX, nameList[x].name, sizeof(char) * (strlen(nameList[x].name) + 1));
	memcpy(nameY, nameList[y].name, sizeof(char) * (strlen(nameList[y].name) + 1));
	xLen = strlen(nameX);
	yLen = strlen(nameY);
	
	/*
	if (xLen != yLen) {
		fatherId = xLen < yLen ? x : y;
		return fatherId;
	}
	*/
	
	fatherId = strcmp(nameX, nameY) < 0 ? x : y;
	return fatherId;	
}

void Union(int x, int y)
{
	int fatherId;
	
	fatherId = FindFather(x, y);	
	if (x == fatherId) {
		parent[y] = fatherId;
		nameList[x].val += nameList[y].val; 
		return;
	}
	parent[x] = fatherId;	
	nameList[y].val += nameList[x].val;
}

void TransNum2A(int x, char *transedA)
{
	int i;
	char numStrTmp[1000];
	int numLen;
	int tmp;
	int curStrLen;
	int curResultLen;
	
	curStrLen = 0;
	curResultLen = 0;	
	while (x != 0) {
		tmp = x % 10;
		numStrTmp[curStrLen++] = tmp + '0';
		x /= 10;
	}
	while (curStrLen > 0) {
		transedA[curResultLen++] = numStrTmp[curStrLen - 1];
		curStrLen -= 1;
	}
	transedA[curResultLen] = '\0';
	return;	
}

char** trulyMostPopular(char** names, int namesSize, char** synonyms, int synonymsSize, int* returnSize)
{
	int i;
	int j;
	int num;
	unsigned int nameHashId;
	unsigned int nameAHashId;
	unsigned int nameBHashId;
	unsigned int nmAFathr;
	unsigned int nmBFathr;
	char nameParsed[1000];
	char nameA[1000];
	char nameB[1000];
	
	static unsigned short int hashIdMap[HASH_VOLUM] = {0};	
	//HashNode hashTbl[1000000];
	char **resultArray;
	int curResultNum;
	int curNameLen;
	char numStrTmp[1000];
	int curResultLen;
	
	curResultNum = 0;
	nameList = (NameStr*)malloc(sizeof(NameStr) * namesSize);
	//memset(nameParsedTable, 0, sizeof(nameParsedTable));
	parent = (int*)malloc(sizeof(int) * namesSize);
	resultArray = (char**)malloc(sizeof(char*) * namesSize);
	
	for (i = 0; i < namesSize; i++) {
		parent[i] = i;
	}	
	
	for (i = 0; i < namesSize; i++) {
		num = 0;
		memset(nameParsed, 0, sizeof(nameParsed));
		ParseName(names[i], nameParsed, &num);
		nameHashId = BKDRHash(nameParsed);
		//nameParsedTable[nameHashId].nameNum = num;
		nameList[i].val = num;
		memcpy(nameList[i].name, nameParsed, sizeof(char) * (strlen(nameParsed) + 1));
		hashIdMap[nameHashId] = i;
		//memcpy(nameParsedTable[nameHashId].name, nameParsed, sizeof(char) * strlen(nameParsed));
	}
	
	for (i = 0; i < synonymsSize; i++) {
		ParseSameName(synonyms[i], nameA, nameB);
		nameAHashId = BKDRHash(nameA);
		nameBHashId = BKDRHash(nameB);
		nmAFathr = Find(hashIdMap[nameAHashId]);
		nmBFathr = Find(hashIdMap[nameBHashId]);
		if (nmAFathr != nmBFathr) {
			Union(nmAFathr, nmBFathr);  //此处需要适特定配
			continue;
		}		
	}
	
	for (i = 0; i < namesSize; i++) {
		if (parent[i] != i) {
			continue;
		}
		curNameLen = strlen(nameList[i].name);
		resultArray[curResultNum] = (char*)malloc(sizeof(char) * (curNameLen + 20));
		memcpy(resultArray[curResultNum], nameList[i].name, sizeof(char) * curNameLen);
		resultArray[curResultNum][curNameLen++] = '(';
		TransNum2A(nameList[i].val, numStrTmp);
		for (j = 0; j < strlen(numStrTmp); j++) {
			resultArray[curResultNum][curNameLen++] = numStrTmp[j];
		}
		resultArray[curResultNum][curNameLen++] = ')';
		resultArray[curResultNum][curNameLen++] = '\0';
		curResultNum += 1;		
	}
		
	*returnSize = curResultNum;
	return resultArray;
}
```