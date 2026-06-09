### 解题思路
两重循环暴力搜索所有可能的子序列

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeZeroSumSublists(struct ListNode* head) {
	if (!head) return head;
	struct ListNode* L = (struct ListNode*)malloc(sizeof(struct ListNode));
	L->next = head;
	struct ListNode* p = L;
	struct ListNode* q = L->next;
	while (p) {
		q = p->next;
		int sum = 0;
		while (q) {
			sum += q->val;
			if (sum == 0) break;
			q = q->next;
		}
		if (q) {
			p->next = q->next;
		}
		else {
			p = p->next;
		}
	}
	return L->next;
}
```