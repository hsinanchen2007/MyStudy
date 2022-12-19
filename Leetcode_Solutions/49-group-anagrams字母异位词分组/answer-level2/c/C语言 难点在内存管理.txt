### 解题思路
思路就是hash
对于c语言，高级数据结构需要自己构造，是此题难点
如果申请最大内存，虽然逻辑没问题，但是会超出内存限制，
如果采用qsort，O(nlogn)，现在的算法不考虑uthash本身的开销，是O(n)

![image.png](https://pic.leetcode-cn.com/8fd5d69fcb1323bf09e9e4a80bd3e7958675a3b1f7c9408fccc8025d0f7322a8-image.png)

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define MY_BASE_SIZE 64
#define MY_MASK_SIZE 26
#define MY_OK 0
#define MY_FAIL (-1)
typedef struct {
    short mask[MY_MASK_SIZE];
    int inx;
    UT_hash_handle hh;
} MyItem;
typedef struct {
    char ***rlt;
    int rltSize;
    int rltCnt;
	int *rltColSize;
    int *returnColumnSizes;
} MyRlt;
typedef struct {
    MyItem *items;
    int itemsSize;
    int itemsCnt;
    MyItem *hh_item;
} MyStatus;
void sFree(MyStatus *s)
{
    MyItem *cur = NULL;
    MyItem *tmp = NULL;
    HASH_ITER(hh, s->hh_item, cur, tmp) {
        HASH_DELETE(hh, s->hh_item, cur);
    }
    s->hh_item = NULL;
    if (s->items == NULL) {
        free(s->items);
        s->items = NULL;
    }
    return;
}
int sInit(MyStatus *s, int strsSize)
{
    s->itemsSize = strsSize;
    s->itemsCnt = 0;
    s->items = (MyItem*)calloc(s->itemsSize, sizeof(MyItem));
    if (s->items == NULL) {
        return MY_FAIL;
    }
    s->hh_item = NULL;
    return MY_OK;
}
int rInit(MyRlt *r, int strsSize)
{
    int i;
    r->rltSize = strsSize;
    r->rltCnt = 0;
    r->rlt = (char***)calloc(r->rltSize, sizeof(char**));
    if (r->rlt == NULL) {
        printf("rInit r->rlt == NULL\n");
        return MY_FAIL;
    }
	r->rltColSize = (int*)calloc(r->rltSize, sizeof(int));
	if (r->rltColSize == NULL) {
		printf("rInit r->rltColSize == NULL\n");
        return MY_FAIL;
	}
	for (i = 0; i < r->rltSize; i++) {
		r->rltColSize[i] = MY_BASE_SIZE;
	}
    r->returnColumnSizes = (int*)calloc(r->rltSize, sizeof(int));
    if (r->returnColumnSizes == NULL) {
        printf("rInit r->returnColumnSizes == NULL\n");
        return MY_FAIL;
    }
    return MY_OK;
}
void calMask(char *str, short mask[MY_MASK_SIZE])
{
    while (*str != '\0') {
        mask[*str - 'a']++;
        str++;
    }
}
void procStrs(MyStatus *s, char ** strs, int strsSize)
{
    int i;
    for (i = 0; i < strsSize; i++) {
        calMask(strs[i], s->items[i].mask);
    }
    return;
}
void proc(MyStatus *s, MyRlt *r, char ** strs, int strsSize)
{
    int i;
    MyItem *item = NULL;
    char **curRow = NULL;
    int curCol = 0;
	char **curRlt = NULL;
    procStrs(s, strs, strsSize);
    for (i = 0; i < strsSize; i++) {
        HASH_FIND(hh, s->hh_item, s->items[i].mask, (sizeof(short) * MY_MASK_SIZE), item);
        if (item == NULL) {
			r->rlt[r->rltCnt] = (char**)calloc(r->rltColSize[r->rltCnt], sizeof(char*));
			if (r->rlt[r->rltCnt] == NULL) {
				printf("proc, r->rlt[r->rltCnt] == NULL\n");
				return;
			}
            curRow = r->rlt[r->rltCnt];
            curCol = r->returnColumnSizes[r->rltCnt];
            curRow[curCol] = strs[i];
            r->returnColumnSizes[r->rltCnt] += 1;
            s->items[i].inx = r->rltCnt;
            r->rltCnt += 1;
            HASH_ADD(hh, s->hh_item, mask, (sizeof(short) * MY_MASK_SIZE), (&s->items[i]));
        } else {
            curRow = r->rlt[item->inx];
            curCol = r->returnColumnSizes[item->inx];
			if (curCol == r->rltColSize[item->inx]) {
				curRlt = (char**)calloc(r->rltColSize[item->inx] + MY_BASE_SIZE, sizeof(char*));
				if (curRlt == NULL) {
					printf("proc, curRlt == NULL\n");
					return;
				}
				memcpy(curRlt, curRow, sizeof(char*) * curCol);
				r->rltColSize[item->inx] += MY_BASE_SIZE;
				free(r->rlt[item->inx]);
				r->rlt[item->inx] = curRlt;
				curRow = r->rlt[item->inx];
			}
            curRow[curCol] = strs[i];
            r->returnColumnSizes[item->inx] += 1;
        }
    }
    return;
}
char *** groupAnagrams(char ** strs, int strsSize, int* returnSize, int** returnColumnSizes){
    int ret;
    MyRlt r = { 0 };
    MyStatus s = { 0 };
    if (strs == NULL || strsSize == 0) {
        *returnSize = 0;
        return NULL;
    }
    ret = rInit(&r, strsSize);
    ret |= sInit(&s, strsSize);
    if (ret != MY_OK) {
        *returnSize = 0;
        return NULL;
    }
    proc(&s, &r, strs, strsSize);
    sFree(&s);
    *returnSize = r.rltCnt;
    *returnColumnSizes = r.returnColumnSizes;
    return r.rlt;
}
```