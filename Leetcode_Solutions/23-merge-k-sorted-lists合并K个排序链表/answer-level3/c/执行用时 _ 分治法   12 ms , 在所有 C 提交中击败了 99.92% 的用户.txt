struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2);//合并两个链表； 

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){

	if(listsSize==0) return NULL;
	if(listsSize==1) return lists[0];
	
	int i,k=listsSize,j;
	
	while(k!=1){
		//为了方便操作，将每次两两合并后的链表数目分为奇数，偶数分别处理 ； 
		if(k%2==0){
			for(i=0,j=0;i<k;i+=2,j++) 
			lists[j]=mergeTwoLists(lists[i], lists[i+1]); 
		}
		else{
			for(i=0,j=0;i<k-1;i+=2,j++) 
			lists[j]=mergeTwoLists(lists[i], lists[i+1]); 
			lists[j++]=lists[k-1];
		}
		k=j;
	}	
	return lists[0];
}


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
	//特殊情况处理； 
	if(l1==NULL&&l2==NULL) return NULL;
	if(l1==NULL) return l2;
	if(l2==NULL) return l1;
	
	struct ListNode* p,*q, *r,*head;
	p=l1;q=l2;
	//处理头结点 
	if(p->val>q->val){
		r=q;head=q;
		q=q->next;
	}
	else{
		r=p;head=p;
		p=p->next;
	}
	//排序； 
	while(p&&q){
		if(p->val>q->val){
			r->next=q;
			q=q->next;
			r=r->next;
		}
		else{
			r->next=p;
			p=p->next;
			r=r->next;
		}
	}
	//当其中一个处理完时，r指向非空链表； 
	if(p==NULL)
		r->next=q;
	else r->next=p;
	
	return head;
}