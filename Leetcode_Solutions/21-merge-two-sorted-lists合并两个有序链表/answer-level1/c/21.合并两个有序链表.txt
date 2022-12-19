### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//二路归并思想
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
       struct ListNode*p,*q,*r,*s,*head;//p扫描l1链表  q扫描l2链表  r指向head链表最后的节点
       head=(struct ListNode*)malloc(sizeof(struct ListNode));
       head->next=NULL;
       p=l1;q=l2;r=head;
       while(p!=NULL&&q!=NULL){
           s=(struct ListNode*)malloc(sizeof(struct ListNode));
           if(p->val<=q->val){
                s->val=p->val;
                r->next=s;
                r=s;
                p=p->next;
           }else{
                s->val=q->val;
                r->next=s;
                r=s;
                q=q->next;
           }
       }
       if(p==NULL){
           while(q!=NULL){
               s=(struct ListNode*)malloc(sizeof(struct ListNode));
               s->val=q->val;
               r->next=s;
               r=s;
               q=q->next;
           }
           r->next=NULL;
       }else{
            while(p!=NULL){
               s=(struct ListNode*)malloc(sizeof(struct ListNode));
               s->val=p->val;
               r->next=s;
               r=s;
               p=p->next;
           }
           r->next=NULL; 
       }
       head=head->next;
     return head; 
}
```