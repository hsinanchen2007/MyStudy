### 解题思路
单链表的运用。

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteNode(struct ListNode* head, int val)
{
    struct ListNode* p;
    struct ListNode * q;
    p=head;
    if(head->val==val)
    {
        head=head->next;
    }
    while(p->val!=val)
    {
        q=p;
        p=p->next;        
    }
    if(p->val==val)
    {
            q->next=p->next;
    }
    return head;
}
```