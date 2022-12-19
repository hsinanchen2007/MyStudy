
### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteDuplicates(struct ListNode* head){
    if(!head||!head->next)
    return head;
    struct ListNode *p=head,*r=head->next;
    while(r)
    {
        if(r->val!=p->val)
        {
            p->next=r;
            p=p->next;
        }
        r=r->next;
    }
    p->next=r;//处理一下边界条件
    return head;
}
```