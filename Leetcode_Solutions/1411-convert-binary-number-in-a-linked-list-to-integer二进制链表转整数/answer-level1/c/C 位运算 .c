```
int getDecimalValue(struct ListNode* head){
	
	if(head == NULL)
	{
		return -1;
	}
	
	struct ListNode *ptr;
	int sum;
	
	ptr = head;
	sum = 0;
	
	while(ptr != NULL)
	{
    	sum = (sum << 1) + ptr->val; //加 改成 或 会简单一些吗?
		ptr = ptr->next;
	}
	
	return sum;
}
```
