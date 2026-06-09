

### 代码

```cpp
class Solution {
public:
	bool isPalindrome(ListNode* head)
	{
		if (head == NULL)
			return true;
		ListNode* FHE = endOfFirstHalf(head);
		ListNode* SHS = reverseList(FHE->next);
		ListNode* p1 = head;
		ListNode* p2 = SHS;
		bool res = true;
		while (p2 && res)
		{
			if (p1->val != p2->val) res = false;
			p1 = p1->next;
			p2 = p2->next;
		}
		FHE->next = reverseList(SHS);
		return res;
	}
private: 
	ListNode* reverseList(ListNode* head)
	{
		ListNode* pre = NULL;
		ListNode* cur = head;
		while (cur)
		{
			ListNode* t = cur->next;
			cur->next = pre;
			pre = cur;
			cur = t;
		}
		return pre;
	}
private:
	ListNode* endOfFirstHalf(ListNode* head)
	{
		ListNode* slow=head;
		ListNode* fast=head;
		while (fast->next && fast->next->next)
		{
			fast = fast->next->next;
			slow = slow->next;
		}
		return slow;
	}
};

```