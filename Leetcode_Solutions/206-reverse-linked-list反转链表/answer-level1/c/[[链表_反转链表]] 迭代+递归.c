
###
迭代：指针p按照现存链表路径往后走，指针head和q滞后依次两两反转节点

```c
struct ListNode* reverseList(struct ListNode* head){
    struct ListNode* p=head;
    struct ListNode* q=NULL;      
    while(p!=NULL){
        p=p->next;
        head->next=q;
        q=head;
        head=p;
    }
    return q;
}
```


###
递归：
递归关系式：调用自身函数反转第二个结点之后的链表
递归出口：反转头两个结点
特殊处理：因为->左边不为NULL（NULL的arrow无意义，为了顾及head->next->next与head->next的使用，首行写if进行特殊处理）

```c
struct ListNode* reverseList(struct ListNode* head){
	if(!head||!head->next){
		return head;
	}
	struct ListNode* ret=reverseList(head->next);
	head->next->next=head;
	head->next=NULL;
	return ret;
}
```