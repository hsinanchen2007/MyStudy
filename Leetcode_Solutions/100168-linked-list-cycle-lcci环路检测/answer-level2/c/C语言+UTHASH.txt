### 解题思路
C语言+UTHASH
### 代码

```c
typedef struct {
	struct ListNode *ptr;
	int val;
	UT_hash_handle hh;
} LNHashNode;
struct ListNode *detectCycle(struct ListNode *head) {
	struct ListNode *ret = NULL;
    LNHashNode *hashhead = NULL;
	LNHashNode *new, *fnd, *cur, *tmp;
	while (head) {
		HASH_FIND(hh, hashhead, &head, sizeof(struct ListNode *), fnd);
		if (fnd) {
			ret = fnd->ptr;
			break;
		}
		new = (LNHashNode *)calloc(1, sizeof(LNHashNode));
		new->ptr = head;
		HASH_ADD(hh, hashhead, ptr, sizeof(struct ListNode *), new);
		head = head->next;
	}
	HASH_ITER(hh, hashhead, cur, tmp) {
		HASH_DEL(hashhead, cur);
		free(cur);
	}
	return ret;
}
```