### 解题思路
加油..

### 代码

```c


struct ListNode* middleNode(struct ListNode* head)
{
	int lenth = 0;
	struct ListNode *temp = head;
	
	for(; temp; lenth++, temp = temp->next);
   
	for(int i = 1; i < (lenth/2)+1; i++, head = head->next);
	
	return head;
}
```