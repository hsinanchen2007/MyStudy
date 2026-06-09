### 解题思路
反转链表然后位运算

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


int getDecimalValue(struct ListNode* head)
{
	struct ListNode* px=head;//指向要删除的节点
	struct ListNode* first=NULL;//指向要反转后的首节点
	struct ListNode* pr=NULL;//指向要删除的节点前一个
    if(head->next==NULL)
    {
        return head->val*1;
    }
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
    int i=0;
    int sum=0;
    while(first)
    {
        sum=sum+first->val*(1<<i++);
        first=first->next;
    }
    return sum;
}
```