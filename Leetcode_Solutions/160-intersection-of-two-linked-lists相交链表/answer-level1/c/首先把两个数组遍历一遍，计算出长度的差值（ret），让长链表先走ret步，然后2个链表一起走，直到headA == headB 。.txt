首先把两个数组遍历一遍，计算出长度的差值（ret），让长链表先走ret步，然后2个链表一起走，直到headA == headB 。

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode Node;
struct Node *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
{
	int ret = 0;
	int lenA = 0;
	int lenB = 0;
	Node* curA = headA;   
	Node* curB = headB;
	while (curA || curB)
	{
		if (curA)
		{
			curA = curA->next;
			++lenA;
		}
		if (curB)
		{
			curB = curB->next;
			++lenB;
		}
	}
	ret = abs(lenA - lenB);
	if (lenA > lenB)
	{
		while (ret)
		{
			headA = headA->next;
			--ret;
		}
		while (headA)
		{
			if (headA == headB)
				return headA;
			else
			{
				headA = headA->next;
				headB = headB->next;
			}
		}
	}
	else
	{
		while (ret)
		{
			headB = headB->next;
			--ret;
		}
		while (headA)
		{
			if (headA == headB)
				return headA;
			else
			{
				headA = headA->next;
				headB = headB->next;
			}
		}
	}

	return NULL;

}
```