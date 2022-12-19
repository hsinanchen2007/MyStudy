### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

struct tstack {
	int t;
	int pos;
	struct tstack *next;
};

struct tstack headSp;

int tstackPush(int t, int pos, struct tstack *head)
{
	struct tstack *tn = (struct tstack *)malloc(sizeof(struct tstack));
	tn->t = t;
	tn->pos = pos;
	tn->next = head->next;
	head->next = tn;
	return 0;
}

int tstackPop(struct tstack *head)
{
	int ret;
	struct tstack *tn = head->next;
	head->next = tn->next;
	ret = tn->pos;
	free(tn);
	return ret;
}

int tstackEmpty(struct tstack *head)
{
	if (head->next == NULL) {
		return 1;
	}
	return 0;
}

int* dailyTemperatures(int* T, int TSize, int* returnSize){

	*returnSize = TSize;

	int *ret = (int *)malloc(TSize * sizeof(int));
	memset(ret, 0, TSize * sizeof(int));

	int i;
	int rPos;
	struct tstack *sp;
	for (i = 0; i < TSize; i++) {
		if (tstackEmpty(&headSp) == 1) {
			printf("T %d i %d \n", T[i], i);
			tstackPush(T[i], i, &headSp);
		} else {
			while (tstackEmpty(&headSp) != 1) {
				sp = headSp.next;
				if (sp->t >= T[i]) {
					break;
				} else {
					rPos = tstackPop(&headSp);
					ret[rPos] = i - rPos;
					printf("ret %d rPos %d \n", ret[rPos], rPos);
				}
			}
			printf("T %d i %d \n", T[i], i);
			tstackPush(T[i], i, &headSp);
		}
	}

	while (tstackEmpty(&headSp) != 1) {
		rPos = tstackPop(&headSp);
	}
	return ret;
}
```