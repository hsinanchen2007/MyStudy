
```
struct ListNode* swapPairs(struct ListNode* head) 
{
	struct ListNode *ret, **last = &ret, *tmp;
	while (head && head->next) {
		*last = head->next;			
		last = &head->next;	

		tmp = head->next->next;
		head->next->next = head;
		head = tmp; 
	}
	*last = head;

	return ret;
}

//更好理解
struct ListNode* swapPairs(struct ListNode* head) 
{
	struct ListNode *ret, **last = &ret, *first, *second;
	while ((first = head) && (second = head->next)) {
		*last = second;			
		last = &first->next;	

		head = second->next;
		second->next = first;
	}
	*last = first;

	return ret;
}
```

