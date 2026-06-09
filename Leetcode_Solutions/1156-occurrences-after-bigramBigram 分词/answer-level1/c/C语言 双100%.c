### 解题思路
使用状态机

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define MAX_CNT 500
struct Word {
	char *start;
	int len;
};
void transToWord(char *ch, struct Word *w)
{
	w->start = ch;
	w->len = strlen(ch);
}
bool wordEqual(struct Word *a, struct Word *b)
{
	if (a->len != b->len) {
		return false;
	}
	if (memcmp(a->start, b->start, a->len) != 0) {
		return false;
	}
	return true;
}
char ** findOcurrences(char * text, char * first, char * second, int* returnSize){
	int i, len, start;
	int stat = 0;
	struct Word fir, sec, cur;
	char **rlt = NULL;
	int cnt;
	rlt = (char**)calloc(MAX_CNT, sizeof(char*));
	cnt = 0;
	transToWord(first, &fir);
	transToWord(second, &sec);
	len = strlen(text);
	start = 0;
	for (i = 0; i <= len; i++) {
		if (text[i] != ' ' && text[i] != '\0') {
			continue;
		}
		cur.start = &text[start];
		cur.len = i - start;
		start = i + 1;
		if (stat == 0) {
			if (wordEqual(&cur, &fir) == true) {
				stat = 1;
			}
		} else if (stat == 1) {
			if (wordEqual(&cur, &sec) == true) {
				stat = 2;
			} else if (wordEqual(&cur, &fir) == true){
				stat = 1;
			} else {
				stat = 0;
			}
		} else if (stat == 2) {
			rlt[cnt] = (char*) calloc(cur.len + 1, sizeof(char));
			memcpy(rlt[cnt], cur.start, cur.len);
			cnt++;
			if (wordEqual(&cur, &fir) == true) {
				stat = 1;
			} else {
				stat = 0;
			}
		}
	}
	*returnSize = cnt;
	return rlt;
}
```