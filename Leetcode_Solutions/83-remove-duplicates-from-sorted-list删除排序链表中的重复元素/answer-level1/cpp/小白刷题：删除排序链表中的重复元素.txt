链表基本操作，删除元素，不过小心next可能会带来的陷阱

代码：

```
class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (head) {
			ListNode* r = head;
			while (r->next) {
				while (r->val == r->next->val) {
					r->next = r->next->next;
					if (!r->next)
						break;
				}
				if (!r->next)
					break;
				else
					r = r->next;
			}
		}
		return head;
	};
};
```
