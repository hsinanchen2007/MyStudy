```C++ []
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* res = new ListNode(-1);
		ListNode* tail = res;
		bool CF = false;	//进位标志
		while (l1 || l2) {
			int add1 = 0, add2 = 0;
			if (l1)
				add1 = l1->val;
			if (l2)
				add2 = l2->val;
			int val = add1 + add2 + CF;
			if (val > 9) {
				val -= 10;
				CF = true;
			}
			else
				CF = false;
			ListNode* tmp = new ListNode(val);
			tail->next = tmp;
			tail = tmp;
			if (l1)
				l1 = l1->next;
			if (l2)
				l2 = l2->next;
		}
		if (CF) {
			ListNode* tmp = new ListNode(1);
			tail->next = tmp;
			tail = tmp;
		}
		return res->next;
	}
};
```
