### 解题思路
C语言最大的问题是没有高级的数据结构，这里创建了struct word用来存储找到的单词信息。包括起始字母地址，长度，出现次数。
记录word长度可以加快单词的比对速度，这得益于不需要每次调用strlen。
### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAX_SIZE 200

struct Word {
	char *start;
	int len;
	int cnt;
};
struct Word* findCurInList(struct Word *list, int cnt, struct Word *cur) 
{
	int i;
	for (i = 0; i < cnt; i++) {
		if (list[i].len != cur->len) {
			continue;
		}
		if (memcmp(list[i].start, cur->start, list[i].len) == 0) {
			return &list[i];
		}
	}
	return NULL;
}
void addToList(struct Word *list, int *cnt, struct Word *cur)
{
	if (*cnt >= MAX_SIZE) {
		printf("buffer is not enough, cnt = %d\n", *cnt);
		return;
	}
	list[*cnt].start = cur->start;
	list[*cnt].len = cur->len;
	list[*cnt].cnt = 1;
	*cnt += 1;
	return;
}
void checkWord(char *A, struct Word *list, int *cnt, int l, int i)
{
	struct Word word;
	struct Word *wordFind = NULL;
	word.start = &A[l];
	word.len = i - l;
	wordFind = findCurInList(list, *cnt, &word);
	if (wordFind == NULL) {
		addToList(list, cnt, &word);
	} else {
		wordFind->cnt += 1;
	}
	return;
}

void processStr(char *A, struct Word *list, int *cnt)
{
	int l;
	int i, len;
	len = strlen(A);
	l = 0;
	for (i = 0; i < len; i++) {
		if (A[i] != ' ') {
			continue;
		}
		checkWord(A, list, cnt, l, i);
		l = i + 1;
	}
	if (l < len) {
		checkWord(A, list, cnt, l, len);
	}
	return;
}
char ** uncommonFromSentences(char * A, char * B, int* returnSize){
	struct Word word;
	struct Word *wordFind = NULL;
	struct Word *list = NULL;
	char **rlt = NULL;
	int rltCnt = 0; 
	int i, cnt;
	list = (struct Word *)calloc(MAX_SIZE, sizeof(struct Word));
	if (list == NULL) {
		*returnSize = 0;
		return NULL;
	}
	cnt = 0;
	processStr(A, list, &cnt);
	processStr(B, list, &cnt);
	rlt = (char**)calloc(MAX_SIZE, sizeof(char*));
	for (i = 0; i < cnt; i++) {
		if (list[i].cnt == 1) {
			rlt[rltCnt] = (char*)calloc(list[i].len + 1, sizeof(char));
			memcpy(rlt[rltCnt], list[i].start, list[i].len);
			rltCnt++;
		}
	}
	*returnSize = rltCnt;
	return rlt;
}
```