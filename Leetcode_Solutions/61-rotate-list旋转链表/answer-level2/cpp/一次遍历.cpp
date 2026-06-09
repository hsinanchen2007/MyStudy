代码功底.
```
class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if (head==NULL || head->next==NULL) return head;
		ListNode *p;
		int n = 1;
		for(p=head; p->next; ++n, p=p->next); // list length
		p->next = head;     // relink to head
		for(k=n-k%n; k--; p=head,head=head->next);
		p->next = NULL;     // cut down list
		return head;
	}
};
```
