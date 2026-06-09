### 解题思路

作弊咯:P
用qsort实现链表排序

![image.png](https://pic.leetcode-cn.com/54657b115fce18bc4dc48277aa1a0f9c9ce62509bf8f5b548ca23f18befd2c6c-image.png)

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int cmp(const void *a, const void *b)
{
	return (*(struct ListNode**)a)->val > (*(struct ListNode**)b)->val;
}
struct ListNode* insertionSortList(struct ListNode* head){
	int i;
	int n = 0;
	struct ListNode **arr = NULL;
	struct ListNode *cur = head;
	
	while (cur != NULL) {
		n++;
		cur = cur->next;
	}
	arr = (struct ListNode**)calloc(n + 1, sizeof(struct ListNode*));
	if (arr == NULL) {
		return NULL;
	}
	cur = head;
	for (i = 0; i < n; i++, cur = cur->next) {
		arr[i] = cur;
	}
	qsort(arr, n, sizeof(struct ListNode*), cmp);
	for (i = 0; i < n; i++) {
		arr[i]->next = arr[i+1];
	}
	cur = arr[0];
	free(arr);
	return cur;
}
```