/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };

    保存找到的相同节点，释放指针即可
 */



struct ListNode* deleteDuplicates(struct ListNode* head){
	struct ListNode* temp =  head;
	while(temp!=NULL&&temp->next!=NULL)
	{
		if(temp->next->val==temp->val)
		{
		    struct ListNode* tem = temp->next;
			temp->next = temp->next->next;
			free(tem);		
		}else{
			temp = temp->next;		
		}
	}
	return head;
    }

