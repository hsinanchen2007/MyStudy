class Solution {
  public:
	  ListNode* deleteDuplicates(ListNode* head) {
		  if (head == NULL || head->next == NULL)return head;
		ListNode* NewHead = new  ListNode(-1);
		NewHead->next = head;
		ListNode* insert = NewHead;
		ListNode* cmpNode = head;
		ListNode* delEnd = NULL;
		ListNode* preNode = head->next;

		bool IsNeedDel = false;

		while (preNode)
		{
			if (preNode->val == cmpNode->val)
			{
				delEnd = preNode;
				IsNeedDel = true;
			}
			else
			{
				if (IsNeedDel)
				{
					insert->next = delEnd->next;
					cmpNode = preNode;
					IsNeedDel = false;
				}
				else
				{
					insert = insert->next;
					cmpNode = preNode;
				}
			}
			preNode = preNode->next;


		}

		if (IsNeedDel)
		{
			insert->next = delEnd->next;
			cmpNode = preNode;
			IsNeedDel = false;
		}

		return NewHead->next;
	}
};