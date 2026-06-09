如果head为空或者head->next为空，那怎么转都一样，直接返回就行  
正常情况下， 就按照直观的方式，每次转一个    
**h->x->x->x->q->p->NULL   --- （1）**  
以h记录head，以q记录倒数第二个，以p记录最后一个    
经过一次旋转后   
**p->h(val)->x->x->x->q->NULL  --- （2）**   
也就是(1)中的p变为第一个，其next为原来的头结点，倒数第二个q变成最后一个节点，其next为NULL，重新更新头部，这时头部是从p开始的     

但是当k很大时，这样会超时，比如三个数，k=200000.反正成倍数的旋转就等于没转，所以**让k对链表长度取模**就行，这样最多旋转n-1次   
```
ListNode * rotateRight(ListNode* head, int k) {
		if (head->next == NULL)
			return head;
		ListNode * h = head;
		ListNode * p = head, *q;
		int cnt = 1; ListNode * t = head;
		while (t->next!= NULL) {
			t = t->next;
			cnt++;
		}
		k = k % cnt;
		for (int i = 0; i < k; i++) {
			p = h; //从头结点开始找倒数第二个节点和最后一个节点
			while (p->next != NULL) {
				q = p;
				p = p->next;
				
			}
			p->next = h;
			q->next = NULL;
			h = p;
		}
		return p;
	}
```
