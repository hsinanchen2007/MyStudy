

暴力法，为a中的每个元素都遍历一次b
```c
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB){
	struct ListNode *l1=headA;
	struct ListNode *l2=headB;
	for(l1=headA;l1;l1=l1->next){ 
		for(l2=headB;l2;l2=l2->next){
	   		if(l1==l2){
    			return l1;
			}
		}
	}
    return NULL;
}
```

官方解答中的路程法，两个指针走到各自链表末尾时滑到另一链表头。假设两链表有重合部分，设在交点前，A链表有a个元素，B链表有b个元素，则a+重合路径+b=b+重合路径+a，最后两指针相遇在相交的第一个节点处。而如果两个链表的最后一个结点不相等，那么两链表不可能相交。
```c
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB){
	struct ListNode *l1=headA,*l2=headB;
	struct ListNode *lastA=NULL;
	struct ListNode *lastB=NULL;	
    if(!l1||!l2){
        return NULL;
    }
	while(l1!=l2){
		l1->next ? (l1=l1->next):(lastA=l1,l1=headB);
		l2->next ? (l2=l2->next):(lastB=l2,l2=headA);
        if(lastA!=NULL && lastB!=NULL && lastA!=lastB){
            return NULL;
        }
	}
    return l1;
}
```