### 解题思路
构成环状后再断环

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* rotateRight(struct ListNode* head, int k) {
	if(!head) return head;
    struct ListNode* p = head;
	int len = 1;
	while (p->next) {
		p = p->next;
		len++;
	}
	p->next = head;
	for (int i = 0; i < len - k%len; i++) {
		p = p->next;
	}
	head = p->next;
	p->next = NULL;
	return head;
}

```