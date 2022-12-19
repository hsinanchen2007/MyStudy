### 解题思路
链表的归并排序效率非常可观，它由顺序表的归并排序的时间复杂度，而且空间复杂度降到了o(1)
归并排序有两个大的步骤
1、利用快慢指针分而治之
2、子链表合并

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* merge_sotrlist(struct ListNode* p,struct ListNode* q){
	struct ListNode *head=(struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode *temp=head;
	while(p!=NULL&&q!=NULL){
		if(p->val<=q->val){
			temp->next=p;
			temp=p;
			p=p->next;
		}else{
			temp->next=q;
			temp=q;
			q=q->next;
		}
	}
    temp->next=(p==NULL)?q:p;
	return head->next;
}
struct ListNode* sortList(struct ListNode* head){
    if(head==NULL||head->next==NULL)return head;
	struct ListNode*p=head;struct ListNode*q=head->next;
	while(q!=NULL&&q->next!=NULL){
		p=p->next;q=q->next->next;
	}
	q=p->next;
	p->next=NULL;
	return merge_sotrlist(sortList(head),sortList(q));
}
```