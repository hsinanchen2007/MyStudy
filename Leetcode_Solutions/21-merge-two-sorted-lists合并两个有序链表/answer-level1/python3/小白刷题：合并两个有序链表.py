首先考虑边界，当l1或l2为空，直接返回另一个链表

当两者均非空时，由于两链表递增，设两指针指向两链表头结点，插入元素较小者，并将对应指针后移，如此循环

当其中一个链表全部插入，则直接将另一个链表尾部接到新链表后面即可，此时不需要循环了

代码：

C++：

```
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (!l1)
			return l2;
		else if (!l2)
			return l1;
		else {
			ListNode* p = l1;
			ListNode* q = l2;
			ListNode* head = new ListNode(0);
			ListNode* r = head;
			if (p->val < q->val) {
				r->val = p->val;
				p = p->next;
			}
			else {
				r->val = q->val;
				q = q->next;
			}
			while (p && q) {
				r->next = new ListNode(0);
				r = r->next;
				if (p->val < q->val) {
					r->val = p->val;
					p = p->next;
				}
				else {
					r->val = q->val;
					q = q->next;
				}
			}
			if (p) {
				r->next = p;
			}
			if (q) {
				r->next = q;
			}
			return head;
		}
	}
};
```
Python3：
```
class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        if not l1:
            return l2
        elif not l2:
            return l1
        else:
            p = l1
            q = l2
            ans = ListNode(0)
            r = ans
            if p.val < q.val:
                r.val = p.val
                p = p.next
            else:
                r.val = q.val
                q = q.next
            while p and q:
                r.next = ListNode(0)
                r = r.next
                if p.val < q.val:
                    r.val = p.val
                    p = p.next
                else:
                    r.val = q.val
                    q = q.next
            if p:
                r.next = p
            if q:
                r.next = q
            return ans
```


