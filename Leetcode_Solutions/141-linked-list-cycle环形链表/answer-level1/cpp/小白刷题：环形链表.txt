思路：双指针，一快一慢

想象一下，如果链表有环，那么快慢指针一定会在环中相遇，凭借这一点判断链表是否有环

代码：
```
class Solution {
public:
	bool hasCycle(ListNode* head) {
		if (head && head->next) {
			ListNode* p = head, * q = head;
			while (q != NULL && q->next != NULL) {
				p = p->next;
				q = q->next->next;
				if (p == q)
					break;
			}
			if (p == q && p != NULL)
				return true;
		}
		return false;
	}
};
```
