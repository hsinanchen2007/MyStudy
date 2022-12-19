```
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode H(-1), *p, *q;
        for(H.next=head, p=&H; p && p->next;){
            for(q=p->next; q && q->next && q->val==q->next->val; q=q->next);
            if(p->next==q) p=p->next;
            else p->next=q?q->next:NULL;
        }
        return H.next;
    }
};
```
