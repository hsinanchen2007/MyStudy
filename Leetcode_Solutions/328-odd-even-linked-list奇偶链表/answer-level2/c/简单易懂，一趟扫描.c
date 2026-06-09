### 解题思路
首先检查异常输入，如果为空或者只有1个或者两个结点，则直接返回。设想将链表分成两组，一组是由head指向的odd链表，另一组是eve指向的even链表，我们的工作就是利用工作指针p和q，把输入链表实际地分离成两个链表，最后p指向odd链表的尾部，让p-next = eve就可以最终将两个链表连接起来。

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* oddEvenList(struct ListNode* head) {
	if (!head || !head->next||!head->next->next)//考虑特殊输入
		return head;
	struct ListNode*eve = head->next, *p = head, *q = eve;
	while (q && q->next)
	{
		p->next = q->next;
		q->next = q->next->next;
		p = p->next;
		q = q->next;
	}
	p->next = eve;
	return head;
}
```