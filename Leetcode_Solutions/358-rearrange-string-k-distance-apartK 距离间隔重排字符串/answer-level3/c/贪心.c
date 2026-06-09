### 解题思路
贪心暴力解

### 代码

```c
#include <stdio.h>
#define MAX_N 26

struct HNode {
	char c;
	int cnt;
};

static int Comp(void *a, void *b)
{
	struct HNode *pa = (struct HNode *)a;
	struct HNode *pb = (struct HNode *)b;
	if (pa->cnt == pb->cnt) {
		return pa->c - pb->c;
	}
	return pb->cnt - pa->cnt;
}
static char *g_ans;
static int g_ansIndex = 0;
static bool leastInterval(char* tasks, int tasksSize, int n){
	struct HNode hash[MAX_N] = { 0 };
	int i, ans;

	for (i = 0; i < tasksSize; i++) {
		hash[tasks[i] - 'a'].c = tasks[i];
		hash[tasks[i] - 'a'].cnt++;
	}
	qsort(hash, MAX_N, sizeof(struct HNode), Comp);
	ans = 0;

	while (hash[0].cnt > 0) {
		i = 0;
		while (i < n) {
			if (hash[0].cnt == 0) {
				break;
			}
			if (i < MAX_N) {
				g_ans[g_ansIndex++] = hash[i].c;
				if (hash[i].cnt > 0) {
					hash[i].cnt--;
				} else {
					return false;
				}
			}
			/* 如果没有就是要空 */
			i++;
			ans++;
		}
		qsort(hash, MAX_N, sizeof(struct HNode), Comp);
	}
	return true;
}

char * rearrangeString(char * s, int k){
	int sLen = strlen(s);
	g_ans = (char *)calloc(1, sizeof(char) * (sLen + 1));
	g_ansIndex = 0;
	if (k == 0) {
		return s;
	}
	if (!leastInterval(s, sLen, k)) {
		return "";
	}
	return g_ans;
}
```