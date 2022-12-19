### 解题思路
中规中矩的解法。

1、排序
2、找到最小inx和
3、将inx和最小的结果找到并返回

![image.png](https://pic.leetcode-cn.com/3107664ab59bae4ba46a97f882013d4ae2b574f945e4f91117fec43065ff14a2-image.png)

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct {
	int inx;
	char *p;
} M_ITEM;

M_ITEM* allocItem(int size)
{
	return (M_ITEM*)calloc(size, sizeof(M_ITEM));
}

char **allocBuf(int size)
{
	return (char**)calloc(size, sizeof(char*));
}
void freePointer(M_ITEM *p1, M_ITEM *p2, M_ITEM *pEqual, char **rlt)
{ 
	if (p1 != NULL) {
		free(p1);
	}
	if (p2 != NULL) {
		free(p2);
	}
	if (pEqual != NULL) {
		free(pEqual);
	}
	if (rlt != NULL) {
		free(rlt);
	}
	return;
}

bool checkPointer(M_ITEM *p1, M_ITEM *p2, M_ITEM *pEqual, char **rlt)
{
	if (p1 != NULL && p2 != NULL && pEqual != NULL  && rlt != NULL) {
		return true;
	} 
	freePointer(p1, p2, pEqual, rlt);
	return false;
}

int cmp(const void *a, const void *b)
{
	return strcmp((*(const M_ITEM*)a).p, (*(const M_ITEM *)b).p);
}

void sortList(M_ITEM *plist, char **list, int listSize)
{
	int i;
	for (i = 0; i < listSize; i++) {
		plist[i].inx = i;
		plist[i].p = list[i];
	}
	qsort(plist, listSize, sizeof(M_ITEM), cmp);
	return;
}

int findMinInx(M_ITEM* p1, int list1Size, M_ITEM* p2, int list2Size)
{
	int ret;
	int list1Inx, list2Inx;
	int curInx;
	int minInx = INT_MAX;
	list1Inx = 0;
	list2Inx = 0;
	while (list1Inx < list1Size && list2Inx < list2Size) {
		ret = strcmp(p1[list1Inx].p, p2[list2Inx].p);
		if (ret == 0) {
			curInx = p1[list1Inx].inx + p2[list2Inx].inx;
			if (curInx < minInx) {
				minInx = curInx;
			}
			list1Inx++;
			list2Inx++;
		} else if(ret > 0) {
			list2Inx++;
		} else {
			list1Inx++;
		}	
	}
	return minInx;
}

int findMinRlt(M_ITEM* p1, int list1Size, M_ITEM* p2, int list2Size, char **rlt, int minInx)
{
	int ret, curInx;
	int list1Inx = 0;
	int list2Inx = 0;
	int rltInx = 0;
	while (list1Inx < list1Size && list2Inx < list2Size) {
		ret = strcmp(p1[list1Inx].p, p2[list2Inx].p);
		if (ret == 0) {
			curInx = p1[list1Inx].inx + p2[list2Inx].inx;
			if (curInx == minInx) {
				rlt[rltInx++] = p1[list1Inx].p;
				minInx = curInx;
			}
			list1Inx++;
			list2Inx++;
		} else if(ret > 0) {
			list2Inx++;
		} else {
			list1Inx++;
		}	
	}
	return rltInx;
}
char ** findRestaurant(char ** list1, int list1Size, char ** list2, int list2Size, int* returnSize){
	int i, ret;
	int equalSize;
	M_ITEM* pEqual = NULL;
	M_ITEM* p1 = NULL;
	M_ITEM* p2 = NULL;
	char **rlt = NULL;
	int minInx;
	int rltInx = 0;

	p1 = allocItem(list1Size);
	p2 = allocItem(list2Size);
	equalSize = list1Size < list2Size ? list1Size : list2Size;
	rlt = allocBuf(equalSize);
	pEqual = allocItem(equalSize);
	if (checkPointer(p1, p2, pEqual, rlt) != true) {
		*returnSize = 0;
		return NULL;
	}
	sortList(p1, list1, list1Size);
	sortList(p2, list2, list2Size);
	minInx = findMinInx(p1, list1Size, p2, list2Size);
	*returnSize = findMinRlt(p1, list1Size, p2, list2Size, rlt, minInx);
	return rlt;
}

```