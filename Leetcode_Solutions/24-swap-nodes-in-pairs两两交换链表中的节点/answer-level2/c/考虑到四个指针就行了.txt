### 解题思路
这是没有头结点的
### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapPairs(struct ListNode* head){
    struct ListNode *p=head,*q,*rear,*front;//关键是用四个指针，front,p,q,rear，并且不断移动
    if(p==NULL||p->next==NULL){
        return head;
    }
    if(p->next!=NULL){
        q=p->next;
        rear=q->next;
        p->next=rear;
        q->next=p;
        head=q;
    }
    front=p;
    while(rear!=NULL&&rear->next!=NULL){
        p=rear;
        q=p->next;
        p->next=q->next;
        q->next=p;
        front->next=q;
        front=p;
        rear=p->next;
    }
    return head;
}
```