### 解题思路
直接尾插法进行翻转即可，然后自建头结点。

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    if(!head)
    return NULL;
    struct ListNode *pre=(struct ListNode*)malloc(sizeof(struct ListNode));
    pre->next=head;
    
    struct ListNode *p=head,*q=head,*r;
    while(q->next)
        q=q->next;
    while(q!=p)
    {
        r=p->next;
        p->next=q->next;
        q->next=p;
        p=r;
    }
    pre->next=q;
    return pre->next;
}
```