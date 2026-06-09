### 解题思路
跌跌撞撞6小时，一把辛酸泪...
代码还有很多地方需要优化，主要是hash生成和比较部分，做得耦合比较紧
![image.png](https://pic.leetcode-cn.com/aecb41abdef2ed6c5fc9cc7cc2d149093f9b6ac7b99dd62d03219385f902d997-image.png)

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MY_BASE_SIZE 1024
#define MY_OK 0
#define MY_FAIL (-1)
typedef struct {
	char *str;
	int cnt;
	UT_hash_handle hh;
} MyItem;
typedef struct {
	char *s;
	int sLen;
	int sSize;
	int *shash;
	
	int wordLen;
	int wordsSize;
	MyItem *wordItems;
	MyItem *lwordItems;
	int lcnt;
} MyStatus;
typedef struct {
	int *rlt;
	int size;
	int cnt;
} MyRlt;
MyItem *g_item = NULL;
MyItem *g_l_item = NULL;
void rFree(MyRlt *r)
{
	if (r->rlt != NULL) {
		free(r->rlt);
		r->rlt = NULL;
	}
	return;
}
int rInit(MyRlt *r)
{
	r->size = MY_BASE_SIZE;
	r->rlt = (int*)calloc(r->size, sizeof(int));
	if (r->rlt == NULL) {
		printf("rInit fail\n");
		return MY_FAIL;
	}
	r->cnt = 0;
	return MY_OK;
}
void rAdd(MyRlt *r, int inx)
{
	if (r->cnt == r->size) {
		printf("rAdd buffer is not enough\n");
		return;
	}
	r->rlt[r->cnt] = inx;
	r->cnt += 1;
	return;
}
void sFree(MyStatus *sta)
{
	int i;
	if (sta->shash != NULL) {
		free(sta->shash);
		sta->shash = NULL;
	}
	if (sta->wordItems == NULL) {
		return;
	}
	for (i = 0; i < sta->wordsSize; i++) {
		if (sta->wordItems[i].str != NULL) {
			HASH_DEL(g_item, (&sta->wordItems[i]));
			free(sta->wordItems[i].str);
			sta->wordItems[i].str = NULL;
		}
	}
	free(sta->wordItems);
	sta->wordItems = NULL;
	g_item = NULL;
	return;
}
int sInit(MyStatus *sta, char * s, char ** words, int wordsSize)
{
	int i;
	MyItem *item = NULL;
	char *tmp = NULL;
	sta->s = s;
	sta->sLen = strlen(s);
	sta->wordLen = strlen(words[0]);
	sta->sSize = sta->sLen / sta->wordLen;
	sta->shash = (int*)calloc(sta->sSize, sizeof(int));
	if (sta->shash == NULL) {
		return MY_FAIL;
	}
	sta->wordsSize = wordsSize;
	sta->wordItems = (MyItem*)calloc(wordsSize * 2, sizeof(MyItem));
	if (sta->wordItems == NULL) {
		free(sta->shash);
		return MY_FAIL;
	}
	sta->lwordItems = sta->wordItems + wordsSize;
	tmp = (char*)calloc(sta->wordLen + 1, sizeof(char));
	for (i = 0; i < wordsSize; i++) {
		strcpy(tmp, words[i]);
		item = NULL;
		HASH_FIND_STR(g_item, tmp, item);
		if (item != NULL) {
			item->cnt++;
		} else {
			sta->wordItems[i].str = (char*)calloc(sta->wordLen + 1, sizeof(char));
			strcpy(sta->wordItems[i].str, tmp);
			sta->wordItems[i].cnt = 1;
			HASH_ADD_STR(g_item, str, (&(sta->wordItems[i])));
		}
	}
	free(tmp);
	return MY_OK;
}
void sInitLItems(MyStatus *sta)
{
	g_l_item = NULL;
	sta->lcnt = 0;
}
void sAddLItems(MyStatus *sta, char *str)
{
	MyItem *item = NULL;
	char *buf = calloc(strlen(str), sizeof(char));
	if (buf == NULL) {
		printf("sAddLItems buf == NULL\n");
		return;
	}
	HASH_FIND_STR(g_l_item, str, item);
	if (item != NULL) {
		item->cnt++;
	} else {
		buf = calloc(strlen(str) + 1, sizeof(char));
		strcpy(buf, str);
		sta->lwordItems[sta->lcnt].cnt = 1;
		sta->lwordItems[sta->lcnt].str = buf;
		HASH_ADD_STR(g_l_item, str, (&sta->lwordItems[sta->lcnt]));
		sta->lcnt++;
	}
	return;
}
void sFreeLItems(MyStatus *sta)
{
	int i;
	for (i = 0; i < sta->lcnt; i++) {
		if (sta->lwordItems[i].str != NULL) {
			HASH_DEL(g_l_item, &sta->lwordItems[i]);
			free(sta->lwordItems[i].str);
			sta->lwordItems[i].str = NULL;
			sta->lwordItems[i].cnt = 0;
		}
	}
}
int procSHash(MyStatus *sta, int inx)
{
	int i;
	int rlt = MY_OK;
	char *tmp = NULL;
	MyItem *item = NULL;
	MyItem *litem = NULL;
	int flag = 0;
	sInitLItems(sta);
	//printf("%s\n", &sta->s[inx]);
	tmp = (char*)calloc(sta->wordLen + 1, sizeof(char));
	for (i = 0; i < sta->wordsSize; i++) {
		memcpy(tmp, &sta->s[inx + sta->wordLen * i], sta->wordLen);
		/* 把判断放在这里是为性能，也是最后一个案例 */
		HASH_FIND_STR(g_item, tmp, item);
		if (item == NULL) {
			flag = 1;
			rlt = MY_FAIL;
			break;
		}
		HASH_FIND_STR(g_l_item, tmp, litem);
		if (litem != NULL && litem->cnt > item->cnt) {
			flag = 1;
			rlt = MY_FAIL;
			break;
		}
		sAddLItems(sta, tmp);
	}
	free(tmp);
	if (flag != 1) {
		for (i = 0; i < sta->wordsSize; i++) {
			if (sta->wordItems[i].str == NULL) {
				continue;
			}
			HASH_FIND_STR(g_l_item, sta->wordItems[i].str, item);
			if (item == NULL || item->cnt != sta->wordItems[i].cnt) {
				//printf("item->cnt = %d, sta->wordItems[i].cnt = [%d]\n", item->cnt, sta->wordItems[i].cnt);
				rlt = MY_FAIL;
				break;
			}
		}
	}
	sFreeLItems(sta);
	return rlt;
}
void proc(MyStatus *sta, MyRlt *r)
{
	int i, j;
	int max;
	max = sta->sLen - sta->wordsSize * sta->wordLen;
	for (i = 0; i <= max; i++) {
		if (procSHash(sta, i) == MY_OK) {
			rAdd(r, i);
		}
	}
	return;
}
int* findSubstring(char * s, char ** words, int wordsSize, int* returnSize){
	int ret;
	MyRlt r = { 0 };
	MyStatus sta = { 0 };
	if (strlen(s) == 0 || wordsSize == 0 || strlen(words[0]) == 0) {
		*returnSize = 0;
		return NULL;
	}
	ret = rInit(&r);
	ret |= sInit(&sta, s, words, wordsSize);
	if (ret != MY_OK) {
		rFree(&r);
		sFree(&sta);
		*returnSize = 0;
		return NULL;
	}
	proc(&sta, &r);
	sFree(&sta);
	*returnSize = r.cnt;
	return r.rlt;
}
```