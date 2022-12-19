struct ListNode* swapPairs(struct ListNode* head){
	struct ListNode* p;
	if(head&&head->next){
//交换前两个
		p=head->next;
		head->next=p->next;
		p->next=head;
		head=p;
//从第三个开始进行交换
		head->next->next=swapPairs(head->next->next);
	}
//其他情况以及递归结束后返回头节点
	return head;
}