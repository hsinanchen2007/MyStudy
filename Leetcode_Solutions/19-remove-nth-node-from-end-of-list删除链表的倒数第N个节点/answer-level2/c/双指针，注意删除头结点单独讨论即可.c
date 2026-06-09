### 解题思路
此处撰写解题思路

### 代码

```c
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
	int i=0;
	struct ListNode *p,*q;
	p=head;q=NULL;
	for(i=0;i<n;i++)
		 p=p->next;
	if(p==NULL){
		q=head;
		head=q->next;

	}else{
		for(q=head;p->next!=NULL;p=p->next,q=q->next);
		p=q->next;
		q->next=p->next;

	}
	return head;	
}
```