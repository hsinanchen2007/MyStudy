### 解题思路
此处撰写解题思路
执行用时 :4 ms, 在所有 C 提交中击败了92.25%的用户
内存消耗 :7.7 MB, 在所有 C 提交中击败了5.02%的用户
用的是一般的算法，内存消耗有点太高了，一会看下大佬的算法。
我能想到的就是两个链表比较然后放入L3，在核心代码之前，列举了一些特殊的情况，应该能够使执行时间变短吧。
### 代码

```c
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode *l3 , *l4;
	l3 = (struct ListNode*)malloc(sizeof(struct ListNode));
	l4 = l3;
	int i = 0, j = 0;
	if (l1 == NULL)
		return l2;
	if (l2 == NULL)
		return l1;
	if (l1 == NULL&&l2 == NULL)
		return NULL;
	while (l1 != NULL && l2 != NULL)
	{
			if (l1->val > l2->val)
			{
				l3->val = l2->val;
				l2 = l2->next;
			}
			else
			{
				l3->val = l1->val;
				l1 = l1->next;
			}
			l3->next = (struct ListNode*)malloc(sizeof(struct ListNode));
			l3 = l3->next;
	}
	while (l2!=NULL)
	{
		l3->val = l2->val;
		l3->next = (struct ListNode*)malloc(sizeof(struct ListNode));
		l2 = l2->next;
		if (l2 != NULL)
			l3 = l3->next;
	}
	while (l1 != NULL)
	{
		l3->val = l1->val;
		l3->next = (struct ListNode*)malloc(sizeof(struct ListNode));
		l1 = l1->next;
		if (l1 != NULL)
			l3 = l3->next;
	}
	l3->next=NULL;
	return l4;
}
```