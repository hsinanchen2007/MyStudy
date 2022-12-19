s->head
t=s
p=s->next
q=p->next
这样p,q控制比较值相等时跳过相等的数，t控制跳过p本身指向的重复出现过的数字
最后返回s->next
```
ListNode * deleteDuplicates(ListNode* head) {
		ListNode * p, *q,*s,*t;
        //处理特殊情况
		if (head == NULL || head->next == NULL)
			return head;
		if (head->next->next == NULL) {
			if (head->val == head->next->val)
				return NULL;
			else
				return head;
		}
		s = new ListNode(0);
		s->next = head;
		t = s;
		p = head;
		q = p->next;
		bool flag;
        //遍历开始
		while (q != NULL) {
			flag = false;
			while (p!=NULL && q!=NULL && p->val == q->val) {
				flag = true;
				p->next = q->next;
				q = q->next;
			}
            //p本身的位置也是重复出现过的数字
			if (flag) {
				t->next = p->next;
				if(p!=NULL)
					p = p->next;
				if(q!=NULL)
					q = q->next;
			}
			else {
				q = q->next;
				p = p->next;
				t = t->next;
			}
		}
		return s->next;

	}
```
