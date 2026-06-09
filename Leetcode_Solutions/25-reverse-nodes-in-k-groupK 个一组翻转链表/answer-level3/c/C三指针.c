```
struct ListNode* reverseKGroup(struct ListNode* head, int k){
    if (!head)
		return NULL;
	struct ListNode *nh = (struct ListNode *)malloc(sizeof(struct ListNode));
	nh->next = head;
	struct ListNode *p = head, *fast = head, *m = head;
	int len = 0;
	while (p){
		p = p->next;
		len++;
	}
	p = nh;
	while ((len - k) >= 0){
		int kt = k;
		while (kt--){
			fast = fast->next;
			m->next = p->next;
			p->next = m;
			m = fast;
		}
		kt = k;
		while (kt--)
			p = p->next;
		p->next = m;
		len -= k;
	}
	head = nh->next;
	free(nh);
	return head;
}
```
