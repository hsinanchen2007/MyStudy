### 解题思路
链表的题，在我总结就是头插法和尾插法的运用，这两种方法可以解决大部分的题目。

我这里单独用一个链表保存大于等于x的，原链表保持不变，那么新链表用尾插法保持相对顺序不变。

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* partition(struct ListNode* head, int x){
    struct ListNode *p=head,*q=NULL,*r=head,*pre;
    if(!head||!head->next)
    return head;
    struct ListNode *H1=(struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode *H2=(struct ListNode*)malloc(sizeof(struct ListNode));
    H1->next=head;
    H2->next=NULL;
    r=H2;
    pre=H1;
    while(p)
    {
        if(p->val<x)
        {
            pre=p;
            p=p->next;
        }
        else
        {
            q=p;
            p=p->next;
            pre->next=p;
            q->next=r->next;
            r->next=q;
            r=r->next;
        }

    }
    pre->next=H2->next;
    return H1->next;
}
```