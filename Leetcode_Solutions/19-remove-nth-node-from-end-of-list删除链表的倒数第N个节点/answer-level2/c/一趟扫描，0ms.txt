```
	struct ListNode *p = head, *t = head;
	while (n--)
		p = p->next;
	if (!p)
		return head->next;
	while (p->next){
		p = p->next;
		t = t->next;
	}		
	t->next = t->next->next;
	return head;
```
