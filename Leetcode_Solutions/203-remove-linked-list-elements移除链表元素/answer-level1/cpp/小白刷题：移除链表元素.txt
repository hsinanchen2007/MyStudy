链表基础操作，删除节点

首先头结点由于没有前驱，作为特殊情况需要另行考虑，指定值若在头结点则将头结点后移

之后设节点进行链表遍历，同样需要注意next带来的空指针陷阱

代码：
```
class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {
		while (head && head->val == val)
			head = head->next;
		if (!head)
			return NULL;
		ListNode* p = head;
		while (p->next) {
			while (p->next->val == val) {
				p->next = p->next->next;
				if (!p->next)
					break;
			}
			if (!p->next)
				break;
			else
				p = p->next;
		}
		return head;
	}
};
```
