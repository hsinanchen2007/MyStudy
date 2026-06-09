### 解题思路
原地逆置链表(删除每个节点然后头插)

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head)
{
	struct ListNode* px=head;//指向要删除的节点
	struct ListNode* first=NULL;//指向要反转后的首节点
	struct ListNode* pr=NULL;//指向要删除的节点前一个
	while(px)
	{
		if(first==NULL)
		{		
			pr=px;
			px=px->next;
			pr->next=NULL;
			first=pr;
		}
		else
		{
			pr=px;
			px=px->next;
			pr->next=first;
			first=pr;
		}
		
	}
	return first;
	
}
```