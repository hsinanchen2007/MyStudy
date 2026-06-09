```
	if (!head || !head->next || !head->next->next)
		return;
	struct ListNode *p = head, *temp = head;
	while (p->next->next)
		p = p->next;
	temp = temp->next;
	head->next = p->next;
	p->next->next = temp;
	p->next = NULL;
	reorderList(temp);
```
