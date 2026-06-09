```
class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		if (head == NULL || head->next == NULL)return head;
		ListNode* pre = head;
		ListNode* cur = head->next;
		ListNode* out= head->next;
		while (pre!=NULL&&cur!=NULL)
		{
			ListNode* temp = cur->next;
			cur->next = pre;
			if (temp == NULL)
			{
				pre->next = NULL;
			}
			else if(temp->next==NULL)
			{
				pre->next = temp;
			}
			else
			{
				pre->next = temp->next;
			}
			pre = temp;
			if (temp == NULL)break;
			cur = temp->next;
		}
		return out;
	}
};
```
