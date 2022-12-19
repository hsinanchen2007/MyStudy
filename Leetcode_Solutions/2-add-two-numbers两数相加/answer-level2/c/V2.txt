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


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *p=l1;
    struct ListNode *q=l2;
    struct ListNode *r,*t;
    r=t=(struct ListNode*)malloc(sizeof(struct ListNode));
    int flag=0;
    while(p!=NULL&&q!=NULL){        
        t->val=(p->val+q->val+flag)%10;
        flag=(p->val+q->val+flag)/10;
        p=p->next;q=q->next;
        if(p!=NULL||q!=NULL||flag!=0){
            t->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            t=t->next;
        }
    }
    while(p!=NULL){
        t->val=(p->val+flag)%10;
        flag = (p->val+flag)/10;
        p=p->next;
        if(p!=NULL||flag!=0){
            t->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            t=t->next;
        }
    }
    while(q!=NULL){
        t->val=(q->val+flag)%10;
        flag = (q->val+flag)/10;
        q=q->next;
        if(q!=NULL||flag!=0){
            t->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            t=t->next;
        }
    }
    if(flag!=0) t->val=flag;t->next=NULL;
    return r;
}
```