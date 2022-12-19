### 解题思路
定义一颗指针，不断获取两个链表中的最小值放在其后，生成一个新链表；
原来的两个链表不断舍弃最小的值，直到至少有一个链表为空；
如果有其中一个链表不为空，直接将之链接到生成的新链表之后。

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode * mergeTwoLists(struct ListNode * l1, struct ListNode * l2)
{
	if(l1 == NULL && l2 ==NULL)return 0;
	if(l1 == NULL)return l2;
	if(l2 == NULL)return l1;

	struct ListNode  *res = NULL;
	
	if(l1->val <= l2->val)
	{
		res = l1;
		l1 = l1->next;
	}
	else
	{
		res = l2;
		l2 = l2->next;
	}
	
	struct ListNode  *r = res;

	while(l1 != NULL && l2 != NULL)
	{
		if(l1->val <= l2->val)
		{
			r->next = l1;
			l1 = l1->next;
		}
		else
		{
			r->next = l2;
			l2 = l2->next;
		}
		r = r->next;
	}
	if(l1 != NULL)
	{
		r->next = l1;
	}
	if(l2 != NULL)
	{
		r->next = l2;
	}
	
	return res;
}
```