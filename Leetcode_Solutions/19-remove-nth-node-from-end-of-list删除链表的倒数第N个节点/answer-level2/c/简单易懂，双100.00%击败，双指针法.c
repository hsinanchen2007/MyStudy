### 解题思路
由于题目n绝对有效，所以不考虑n = 0。置双指针pre和q，指针q向先后走n步，然后双指针同时向后走，当p走到最后结点的时候，pre指向倒数第n个结点的前驱，删除即可。注意当q = NULL时，说明要删除头结点。

### 代码

```c
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
	struct ListNode *pre = head, *q = pre;
	while (n--)//q先向后走n步
		q = q->next;
    if(!q)//q为NULL，要删除头结点
    {
        head = head->next;
        return head;
    }
	while (q->next != NULL)//q不是NULL，双指针同时向后走
	{
		q = q->next;
		pre = pre->next;
	}
//此时pre指向要删除结点的前驱
	pre->next = pre->next->next;
	return head;
}

```