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

//自己一次成功
struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *p,*t,*h;//用头插法来倒置链表
    if(head==NULL)
        return NULL;
    h=(struct ListNode *)malloc(sizeof(struct ListNode));
    h->next=NULL;
    p=head;
    while(p)
    {
        t=p;
        p=p->next;
        t->next=h->next;
        h->next=t;
    }
    head=h->next;
    return head;
}
```