普通遍历方法：
```cpp
class Solution
{
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
	{
		if (!l1)
		{
			return l2;
		}
		if (!l2)
		{
			return l1;
		}
		ListNode* head = new ListNode(0);
		ListNode* ptr = head;
		while (1)
		{
			if (l1->val < l2->val)
			{
				ptr->next = l1;
				ptr = ptr->next;
				if (l1->next != nullptr)
				{
					l1 = l1->next;
				}
				else
				{
					l1->next = l2;
					break;
				}
			}
			else
			{
				ptr->next = l2;
				ptr = ptr->next;
				if (l2->next != nullptr)
				{
					l2 = l2->next;
				}
				else
				{
					l2->next = l1;
					break;
				}
			}
		}
		return head->next;
	}
};
```
```cpp
递归方法：
class Solution
{
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
	{
		if (!l1)
		{
			return l2;
		}
		if (!l2)
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