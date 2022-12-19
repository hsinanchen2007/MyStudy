### 解题思路
再创建一个链表，把参数里面的元素头插法插入到新的链表中

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *head2=(struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode *temp = head2;
	temp->next = NULL;
	struct ListNode *temp2 =head;
	while (temp2!=NULL)
	{
		struct ListNode *pp = (struct ListNode*)malloc(sizeof(struct ListNode));
        pp->next=NULL;
		pp->val = temp2->val;
		pp->next = temp->next;
		temp->next = pp;
		temp2 = temp2->next;
	}
	return head2->next;
}
```