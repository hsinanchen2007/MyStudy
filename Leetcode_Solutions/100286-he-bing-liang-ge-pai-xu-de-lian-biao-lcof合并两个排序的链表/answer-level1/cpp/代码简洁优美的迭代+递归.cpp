```cpp
迭代
class Solution
{
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
	{
		ListNode* pre_head = new ListNode(-1);
		ListNode* pre = pre_head;
		while (l1 && l2)
		{
			if (l1->val < l2->val)
			{
				pre->next = l1;
				pre = pre->next;
				l1 = l1->next;
			}
			else
			{
				pre->next = l2;
				pre = pre->next;
				l2 = l2->next;
			}
		}
		if (l1)
		{
			pre->next = l1;
		}
		if (l2)
		{
			pre->next = l2;
		}
		ListNode* p = pre_head->next;
		delete pre_head;
		return p;
	}
};
递归：
class Solution
{
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
	{
		if (l1 == nullptr)
		{
			return l2;
		}
		if (l2 == nullptr)
		{
			return l1;
		}
		if (l1->val < l2->val)
		{
			l1->next = mergeTwoLists(l1->next, l2);
			return l1;
		}
		else
		{
			l2->next = mergeTwoLists(l1, l2->next);
			return l2;
		}
	}
};
```