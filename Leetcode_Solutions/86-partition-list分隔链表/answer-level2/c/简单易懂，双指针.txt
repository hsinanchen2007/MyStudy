### 解题思路
一边扫描，新建两个链表，分别存储两种要求的结点，最后拼在一起，时间复杂度线性，空间复杂度线性，没有原地分割。按照官方思路原地做更简单。

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* partition(struct ListNode* head, int x) {
	struct ListNode * p = head;
	struct ListNode* big = (struct ListNode*)malloc(sizeof(struct ListNode)), *b = big;
	struct ListNode* small = (struct ListNode*)malloc(sizeof(struct ListNode)), *s = small;
	big->next = NULL;
	small->next = NULL;
	while (p)
	{
		if (p->val >= x)
		{
			struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
			temp->next = NULL;
			temp->val = p->val;
			b->next = temp;
			b = temp;
		}
		else
		{
			struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
			temp->next = NULL;
			temp->val = p->val;
			s->next = temp;
			s = temp;
		}
		p = p->next;
	}
	s->next = big->next;
	s = small->next;
	free(small);
	free(big);
	return s;
}
```