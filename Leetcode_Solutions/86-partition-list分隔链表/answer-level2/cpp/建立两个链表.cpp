```
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode A(-1), B(-1), *p, *q;
        for(p=&A, q=&B; head; head=head->next)
            if(head->val<x) p=p->next=head;
            else q=q->next=head;
        p->next=B.next;
        q->next=NULL;
        return A.next;
    }
};
```
