### 解题思路
此处撰写解题思路
其实这道题主要是考虑进位问题，当一个链表为空，另一个不为空以及两个均为空，但是仍存在进位情况得到特殊情形的判断。
### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    if(l1==NULL&&l2==NULL)return NULL;
    if(l1==NULL&&l2!=NULL)return l2;
    if(l2==NULL&&l1!=NULL)return l1;
    struct ListNode *a,*p,*q;
    a=p=(struct ListNode *)malloc(sizeof(struct ListNode));
    int t=0;
    a=NULL;
    while(l1!=NULL&&l2!=NULL){
        q=(struct ListNode*)malloc(sizeof(struct ListNode));
        q->val=l1->val+l2->val+t;
        if(q->val>=10){
            t=1;
            q->val-=10;
        }
        else{
            t=0;
        }
        if(a==NULL){
            a=p=q;
        }
        else{
            p->next=q;
            p=q;
        }
        l1=l1->next;
        l2=l2->next;
    }
    if(l1!=NULL){
        while(l1){
            q=(struct ListNode*)malloc(sizeof(struct ListNode));
        q->val=l1->val+t;
        if(q->val>=10){
            t=1;
            q->val-=10;
        }
        else{
            t=0;
        }
        p->next=q;
        p=q;
        l1=l1->next;
        }
        
    }
    else if(l2!=NULL){
        while(l2!=NULL){
        q=(struct ListNode*)malloc(sizeof(struct ListNode));
        q->val=l2->val+t;
        if(q->val>=10){
            t=1;
            q->val-=10;
        }
        else{
            t=0;
        }
        p->next=q;
        p=q;
        l2=l2->next;
        }
    }
    if(t==1){
        q=(struct ListNode*)malloc(sizeof(struct ListNode));
        q->val=t;
        p->next=q;
        p=q;
    }
    p->next=NULL;
    return a;
}
```