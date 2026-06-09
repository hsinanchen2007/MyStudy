### 解题思路
二路归并，遍历一遍两个链表即可

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
    struct ListNode *x,*r,*s;
    x=(struct ListNode *)malloc(sizeof(struct ListNode));
    r=x;
    while(l1!=NULL&&l2!=NULL){
    if(l1->val<l2->val){
        s=(struct ListNode *)malloc(sizeof(struct ListNode));
        s->val=l1->val;
        l1=l1->next;
        r->next=s;r=s;
    }
    else{
        s=(struct ListNode *)malloc(sizeof(struct ListNode));
        s->val=l2->val;
        l2=l2->next;
        r->next=s;r=s;
    }
}
    while(l1!=NULL){
        s=(struct ListNode *)malloc(sizeof(struct ListNode));
        s->val=l1->val;
        r->next=s;r=s;
        l1=l1->next;
    }
    while(l2!=NULL){
        s=(struct ListNode *)malloc(sizeof(struct ListNode));
        s->val=l2->val;
        r->next=s;r=s;
        l2=l2->next;
    }
    r->next=NULL;
    return x->next;
}
```