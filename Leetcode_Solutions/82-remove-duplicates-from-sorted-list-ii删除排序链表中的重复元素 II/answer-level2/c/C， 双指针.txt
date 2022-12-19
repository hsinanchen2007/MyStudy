```
int destroy(struct ListNode* slow, struct ListNode* fast);
 
struct ListNode* deleteDuplicates(struct ListNode* head){
	
	struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
	dummy->next = head;
    dummy->val = 0;
	
	struct ListNode *slow = dummy, *fast = slow->next; //slow表示待返回链表的尾部， fast为探查的节点。
	
	while(fast != NULL)
	{
		if(fast->next == NULL || fast->next->val != fast->val) //此时fast为重复节点的最后一个或者非重复节点
		{
			int count = destroy(slow, fast);//将slow和fast之间的节点全部free；
			//删除了至少一个节点，说明fast是一个重复点，也需要删除。
			if(count != 0)
			{
				slow->next = fast->next;
				free(fast);
				fast = slow->next;
                //将slow和之后的链表连在一起
			}
			else
			{
				slow->next = fast;
				slow = slow->next;
				fast = slow->next;
			}
		}
		else
		{
			fast = fast->next;
		}
	}
	
	struct ListNode* ret = dummy->next;
	free(dummy);
	
	return ret;
}

int destroy(struct ListNode* slow, struct ListNode* fast)
{
	struct ListNode* ptr = slow->next;
	int count = 0;
	
	while(ptr != fast)
	{
		struct ListNode* temp = ptr->next;
		free(ptr);
		ptr = temp;
		count++;
	}
	
	return count;
}
```
