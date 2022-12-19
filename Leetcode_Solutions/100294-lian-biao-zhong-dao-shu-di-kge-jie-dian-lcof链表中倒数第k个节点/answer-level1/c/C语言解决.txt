### 解题思路
首先求出传入链表的长度，然后用长度减去传入的k值，此值再加一就是其位置。

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* getKthFromEnd(struct ListNode* head, int k){
    int len = 0;
	struct ListNode *temp = head;
	while (temp!=NULL)
	{
		len++;
		temp = temp->next;
	}
	struct ListNode *getlist=head;
	for (int i = 1; i <= len; i++)
	{
		if (i<=len-k)
		{
			getlist = getlist->next;
		}
		else
		{
			return getlist;
		}
	}
    return getlist;
}
```