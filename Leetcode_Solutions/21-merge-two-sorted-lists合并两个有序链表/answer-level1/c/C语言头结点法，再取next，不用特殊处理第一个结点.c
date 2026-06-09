### 解题思路
第一种方法是需要申请额外空间的，第二种方法不用申请额外空间。
在普通局，一般不要破坏原链表，所以求稳就用第一种方法。
你要是能秀起来就用第二种方法，第二种方法时间空间都省了不少。

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *l3=(struct ListNode*)malloc(sizeof(struct ListNode)),*t,*p,*q;
	l3->next=NULL;l3->val=0;
	p=l1;q=l2;t=l3;
	while(p!=NULL&&q!=NULL){
		struct ListNode *n=(struct ListNode*)malloc(sizeof(struct ListNode));
		if(p->val<=q->val){
			n->val=p->val;
			n->next=NULL;
			t->next=n;
			t=t->next;
			p=p->next;
		}else{
			n->val=q->val;
			n->next=NULL;
			t->next=n;
			t=t->next;
			q=q->next;
		}
	}
	while(p){
		struct ListNode *n=(struct ListNode*)malloc(sizeof(struct ListNode));
		n->val=p->val;
		n->next=NULL;
		t->next=n;t=t->next;p=p->next;
	}
	while(q){
		struct ListNode *n=(struct ListNode*)malloc(sizeof(struct ListNode));
		n->val=q->val;
		n->next=NULL;
		t->next=n;t=t->next;q=q->next;
	}
	return l3->next;
}
```
不用分配额外空间的方法
```c
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *head=(struct ListNode*)malloc(sizeof(struct ListNode));
    head->val=0;
    head->next=NULL;
    struct ListNode *p1,*p2,*q;
    p1=l1;p2=l2;q=head;
    while(p1!=NULL&&p2!=NULL){
        if(p1->val>p2->val){
            q->next=p2;
            p2=p2->next;
        }else{
            q->next=p1;
            p1=p1->next;
        }
        printf("%d",q->val);
        if(q->next!=NULL){
            q=q->next;
        }
        
    }
    if(p1!=NULL){
        q->next=p1;
    }
    if(p2!=NULL){
        q->next=p2;
    }
    return head->next;
}
```