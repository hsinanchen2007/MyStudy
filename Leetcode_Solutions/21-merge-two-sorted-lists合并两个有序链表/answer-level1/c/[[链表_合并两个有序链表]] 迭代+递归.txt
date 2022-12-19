
迭代

```c
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){	
    if(!l1 && !l2) return NULL;
    if(!l1 && l2)  return l2;
    if(!l2 && l1)  return l1;
    struct ListNode *head; 
    l1->val < l2->val ? (head=l1,l1=l1->next):(head=l2,l2=l2->next);
    struct ListNode *cur=head;     
    while(l1 && l2){
        if(l1->val < l2->val){
            cur->next=l1;
            l1=l1->next;
        }else{
            cur->next=l2;
            l2=l2->next;
        }
        cur=cur->next;
    }
    if(!l1)  cur->next=l2;
    if(!l2)  cur->next=l1;
    return head;
}
```

递归
递归关系：调用自身函数排好第二个节点之后的链表
递归出口：头个节点的情况，l1还是l2的值小？
```c
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){	
	if (!l1){
		return l2;		
	}
	if (!l2){
		return l1;		
	}
	if (l1->val < l2->val){
		l1->next = mergeTwoLists(l1->next, l2);
		return l1;
	}else{
		l2->next = mergeTwoLists(l2->next，l1);
		return l2;
	}
}
```