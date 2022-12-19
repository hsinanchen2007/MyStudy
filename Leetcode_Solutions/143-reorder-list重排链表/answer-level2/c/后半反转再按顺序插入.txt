### 解题思路
先将后半结点摘下来独立链表，然后再用头插法反转，最后两链表互插搞定
### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

void reverse_list(struct ListNode* start)
{
    if(start==NULL || start->next==NULL || start->next->next==NULL)
        return;
    struct ListNode *p=start->next;
    struct ListNode *q=p->next;
    p->next=NULL;
    while(q!=NULL)
    {
        struct ListNode *temp=q;
        q=q->next;
        temp->next=start->next;
        start->next=temp;
    }
}

void reorderList(struct ListNode* head){
    if(head==NULL || head->next==NULL || head->next->next==NULL)
        return;
    struct ListNode *p=head,*q=head;
    while(q->next!=NULL)
    {
        q=q->next;
        if(q->next==NULL)
            break;
        p=p->next;
        q=q->next;
    }
    struct ListNode *start=(struct ListNode*)malloc(sizeof(struct ListNode));
    start->next=p->next;
    p->next=NULL;
    reverse_list(start);
    q=start->next;
    p=head;
    while(q!=NULL)
    {
        struct ListNode *temp=q;
        q=q->next;
        temp->next=p->next;
        p->next=temp;
        p=temp->next;
    }

}
```