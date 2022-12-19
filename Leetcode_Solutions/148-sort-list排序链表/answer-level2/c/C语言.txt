### 解题思路
开辟数组空间进行排序，然后依次遍历链表进行赋值。
### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#define MAXLEN 100000
int Compare(const void *a, const void *b)
{
	return *(int*)a > *(int*)b;
}

struct ListNode* sortList(struct ListNode* head)
{
	if (head == NULL) {
		return NULL;
	}
	
	int *result = (int*)malloc(sizeof(int) * MAXLEN);
	if (result == NULL) {
		return NULL;
	}
	
	int returnSize = 0;
	struct ListNode *phead = head;
	while (phead) {
		result[returnSize++] = phead->val;
		phead = phead->next;
	}
	
	qsort(result, returnSize, sizeof(int), Compare);
	
	phead = head;
	returnSize = 0;
	while (phead) {
		phead->val = result[returnSize];
		phead = phead->next;
		returnSize++;
	}
	
	return head;
}
```