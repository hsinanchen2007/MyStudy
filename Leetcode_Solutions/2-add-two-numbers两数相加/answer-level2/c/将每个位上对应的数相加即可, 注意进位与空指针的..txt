struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
	int flag = 0;
	int temp_val;
	struct ListNode *n = NULL;
	struct ListNode *p = NULL;
	static struct ListNode *tail = NULL;
	
	while(l1 || l2 || flag == 1)
	{
		n = (struct ListNode *)malloc(sizeof(struct ListNode));
		if(n == NULL)
		{
			printf("内存申请失败了!\n");
			exit(EXIT_FAILURE); 
		}
		else
		{
			if(flag == 1)
			{
			temp_val += 1; 
			flag = 0;
			}
			
		if(l1 != NULL && l2 != NULL)
		temp_val += l1->val + l2->val;
			
		else if(l1 != NULL && l2 == NULL)
		temp_val += l1->val;
		
		else if(l1 == NULL && l2 != NULL)
		temp_val += l2->val;
	
		if(temp_val >= 10)
			{
				temp_val = temp_val-10;
				flag = 1;
			}
		
		n->val = temp_val;
			 
	    if(p == NULL)
			{
				p = n;
				n->next = NULL;
			}
		else
			{
				tail->next = n;
				n->next = NULL;
			}
			tail = n;	
		} 
			
			temp_val = 0;
	
			if(l1)
			l1 = l1->next;
			
			if(l2)
			l2 = l2->next;
		}
        
		return p;
	}