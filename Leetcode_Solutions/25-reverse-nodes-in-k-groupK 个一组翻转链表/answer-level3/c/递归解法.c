```
struct ListNode* reverseKGroup(struct ListNode* head, int k){
	int num = 0;
	struct ListNode* node = head;
	while (node != NULL) {
		num++;
		node = node->next;
	}
	if (num < k) 
		return head;
	
	struct ListNode* L= (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode *p, *r;
	p = head;
	L->next = NULL;
	int n = k;
	while (n--) {
		r = p->next;
		p->next = L->next;
		L->next = p;
		p = r;
	}
	if (p != NULL) {
		head->next = reverseKGroup(p, k); //这里的head一开始写成p，导致链表断裂
	}
	return L->next;
}
```
