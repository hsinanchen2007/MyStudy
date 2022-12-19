**递归**
```
public:
ListNode* swapPairs(ListNode* head) {
	//ListNode* H = new ListNode(0);
	//H->next = head->next;
	if ((head==NULL)||head->next==NULL) {
		return head;
	}
	ListNode* temp = new ListNode(0);
	temp = head->next->next;
	head->next->next = head;
	head = head->next;
	head->next->next = temp;

	head->next->next = swapPairs(head->next->next);

	return head;
}
};
```
