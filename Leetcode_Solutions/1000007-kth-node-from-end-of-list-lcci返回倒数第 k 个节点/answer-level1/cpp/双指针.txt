代码中没有判断链表的长度小于k的情况，实际生产中要排除。
```C++ []
class Solution {
public:
	int kthToLast(ListNode* head, int k) {
		ListNode* cur = head;
		for (int i = 0; i < k; i++)
			head = head->next;
		while (head) {
			head = head->next;
			cur = cur->next;
		}
		return cur->val;
	}
};
```
