### 解题思路
先不管random指向哪里，先把单链表复制了。复制完单链表，再设置两个指针，p扫描给定的链表，q扫描新的链表，对于老链表的每个结点，从头到尾扫描找到其random指向的结点，与此同时新链表做同样的动作，这样就知道了新链表结点的random该指向谁了。时间复杂度是平方复杂度。空间复杂度是常数。因为没有充分利用原来链表的位置信息，导致时间复杂度比较高，需要向着官方解法的第三种学习，就地利用源链表的位置信息，非常巧妙。

### 代码

```c
struct Node* copyRandomList(struct Node* head) {
	if (!head)
		return NULL;
	struct Node* head2 = NULL, *p = NULL,*q = NULL;
	if (!head->next)//只有一个结点
	{
		struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
		temp->next = NULL;
		temp->val = head->val;
		if (head->random == head)
			temp->random = temp;
		else
			temp->random = NULL;
		return temp;
	}
	//两个节点以上
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->next = NULL;
	temp->val = head->val;
	head2 = temp;
	q = head2;
	p = head->next;
	while (p)
	{
		struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
		temp->next = NULL;
		temp->val = p->val;
		q->next = temp;
		q = q->next;
        p = p->next;
	}
	p = head;
	q = head2;
	while (p)
	{
		struct Node* pr = head, *qr = head2;
		if (!p->random)
			q->random = NULL;
		else
		{
			while (pr != p->random)
			{
				pr = pr->next;
				qr = qr->next;
			}
			q->random = qr;
		}
		p = p->next;
		q = q->next;
	}
	return head2;
}
```