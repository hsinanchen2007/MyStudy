### 解题思路
c代码

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode *p, *q, *head, *cur, *tail;
	head = NULL;
	tail = (struct ListNode* )malloc(sizeof(struct ListNode));
	int t, j=0;
	for (p = l1, q = l2; p != NULL || q != NULL || j==1;)
	{
		cur =(struct ListNode* )malloc(sizeof(struct ListNode));
		t = 0;
		if (j>0)
		{
			t = t + j;
		}
		j = 0;
		t = t + p->val + q->val;
		if (t>9)
		{
			t = t % 10;
			j = 1;
		}
		cur->val = t;
		if (head == NULL)
			head = cur;
		else
			tail->next = cur;
		tail = cur;

		p=p->next;
		q=q->next;

		if (p == NULL && q != NULL)
		{
			p = (struct ListNode* )malloc(sizeof(struct ListNode));
			p->val = 0;
			p->next = NULL;
		}
		if (q == NULL && p != NULL)
		{
			q = (struct ListNode* )malloc(sizeof(struct ListNode));
			q->val = 0;
			q->next = NULL;
		}
        if(q == NULL && p == NULL&&j==1)
        {
            p = (struct ListNode* )malloc(sizeof(struct ListNode));
            p->val = 0;
			p->next = NULL;
			q = (struct ListNode* )malloc(sizeof(struct ListNode));
			q->val = 0;
			q->next = NULL;
        }
	}
	tail->next = NULL;
	return head;
}
```