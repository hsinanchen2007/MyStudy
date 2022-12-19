### 解题思路
记得对齐两个链表，可以省去不少麻烦，注意进位以及9+1=10这样的情况。

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
	struct ListNode*p1 = l1, *p2 = l2,*tail;
	struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));//添加头结点
	head->val = 0; head->next = NULL; tail = head;
	int len1 = 1, len2 = 1, add = 0;
	while (p1->next)
	{
		len1++;
		p1 = p1->next;
	}
	while (p2->next)
	{
		len2++;
		p2 = p2->next;
	}
	if (len1 > len2)
	{
		for (int i = 0; i < len1 - len2; ++i)
		{
			struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
			temp->next = NULL;
			temp->val = 0;
			p2->next = temp;
			p2 = temp;
		}
	}
	else if (len1 < len2)
	{
		for (int i = 0; i < len2 - len1; ++i)
		{
			struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
			temp->next = NULL;
			temp->val = 0;
			p1->next = temp;
			p1 = temp;
		}
	}
	p1 = l1; p2 = l2;//以上都是准备工作
	while (p1)
	{
		struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
		temp->next = NULL;
		if ((p1->val + p2->val + add) >= 10)
		{
			temp->val = (p1->val + p2->val + add) % 10;
			add = 1;
		}
		else
		{
			temp->val = (p1->val + p2->val) % 10 + add;
			add = 0;
		}
		tail->next = temp;
		tail = temp;
		p1 = p1->next;
		p2 = p2->next;
	}
	if (add)//9+1=10的情况
	{
		struct ListNode *temp = (struct ListNode*)malloc(sizeof(struct ListNode));
		temp->val = 1;
		temp->next = NULL;
		tail->next = temp;
	}
	return head->next;//去头结点
}
```