### 解题思路
1.正常链表删除操作 2.递归
### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//1.常规操作
struct ListNode* deleteDuplicates(struct ListNode* head)
{
	struct ListNode* px=head;//指向要删除的元素
	struct ListNode* pr=NULL;//指向要删除的元素的前一个元素
	struct ListNode* first=head;//遍历指针
    if(px==NULL)
    {
        return NULL;
    }
	pr=px;
	px=px->next;
	while(px)
	{
		if(pr->val==px->val)
		{
			pr->next=px->next;
			px->next=NULL;
			free(px);
			px=pr->next;
		}
		else
		{
			pr=px;
			px=px->next;
		}
	}
    return head;
}
//2.递归
struct ListNode* deleteDuplicates(struct ListNode* head)
{
    if(head==NULL||head->next==NULL)
    {
        return head;
    }
    while(head->next)
    {
        if(head->val==head->next->val)
        {
            head=head->next;
        }
        else
        {
            head->next=deleteDuplicates(head->next);
            break;
        }
    }
    return head;
}
```