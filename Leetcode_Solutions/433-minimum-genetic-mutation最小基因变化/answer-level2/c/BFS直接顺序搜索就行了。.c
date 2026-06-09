### 解题思路
此处撰写解题思路

### 代码

```c
struct MutNode {
	char *ch;
	int step;
	struct MutNode *next;
};

int FindStringCmp(char *a, char *b, int diff, int len)
{
	int i;
	int cnt = 0;
	for (i = 0; i < len; i++) {
		if (a[i] != b[i]) {
			cnt++;
		}
	}
	if (cnt == diff) {
		return 1;
	}
	return -1;
}

int BFS(char *start, char *end, char **bank, int bankSize, int *flag)
{
	int i;
	int ret;
	int len = strlen(start);
	struct MutNode *head = (struct MutNode *)malloc(sizeof(struct MutNode));
	head->ch = start;
	head->step = 0;
	head->next = NULL;

	struct MutNode *pos = head;
	struct MutNode *tail = pos;

	while (pos != NULL) {
		ret = strcmp(pos->ch, end);
		if (ret == 0) {
			return pos->step;
		}
		for (i = 0; i < bankSize; i++) {
			if (flag[i] == 1) {
				continue;
			}
			ret = FindStringCmp(pos->ch, bank[i], 1, len);
			if (ret != 1) {
				continue;
			}
			tail->next = (struct MutNode *)malloc(sizeof(struct MutNode));
			tail->next->ch = bank[i];
			tail->next->step = pos->step + 1;
			tail->next->next = NULL;
			tail = tail->next;
			flag[i] = 1;
		}
		pos = pos->next;
	}
	return -1;
}


int minMutation(char * start, char * end, char ** bank, int bankSize){

	int i;
	int ret = -1;
	int *flag = (int *)malloc(bankSize * sizeof(int));
	memset(flag, 0, bankSize * sizeof(int));

	for (i = 0; i < bankSize; i++) {
		ret = strcmp(end, bank[i]);
		if (ret == 0) {
			//flag[i] = 1;
			break;
		}
	}

	if (ret != 0) {
		printf("fail 1 \n");
		return -1;
	}

	ret = BFS(start, end, bank, bankSize, flag);

	printf("ret %d \n", ret);

	return ret;
}
```