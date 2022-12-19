提供一个初学者思路，效率空间都不错，要是有bug，请指正

```
struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
	struct ListNode *p, *q, *new;
	struct ListNode HEAD;
	int index, num = m;
	
	HEAD.next = head;

	if(m >= n) {
		return head;
	}

	/* 保存第一个前驱节点 */
	new = &HEAD;
	while( num > 1 ) {
		new = new->next;
		num--;
	}
	p = new->next;

	/* 翻转[m, n]区间链表 */
	index = 0;
	while(index < n-m)
	{
		q = p->next;
		p->next = q->next;
		q->next = new->next;
		new->next = q;
		index++;
	}

	return HEAD.next;
}
```
