
执行用时 :0 ms, 在所有 C 提交中击败了100.00%的用户
内存消耗 :7.1 MB, 在所有 C 提交中击败了96.52%的用户
struct ListNode* partition(struct ListNode* head, int x){
	if (!head)
		return NULL;
	struct ListNode* newHead = (struct ListNode*)malloc(sizeof(struct ListNode));
	newHead->next = head;
	struct ListNode* fast = head, *m = newHead;
	head = newHead;
	while (fast){
		if (fast->val < x){
			m->next = fast->next;            
			fast->next = head->next;
			head->next = fast;
			head = head->next;
			fast = fast->next;
            m = head;
		}
		else{
			m = fast;
			fast = fast->next;
		}
	}
	head = newHead->next;
	free(newHead);
	return head;
}