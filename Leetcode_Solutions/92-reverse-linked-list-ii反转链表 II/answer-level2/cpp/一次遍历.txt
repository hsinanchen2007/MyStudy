```
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode H(-1), *left, *right;
        for(n=n-m+1, H.next=head, left=&H; --m; left=left->next);
        for(right=NULL, head=left->next; n--; swap(head,right))
            swap(right,head->next);
        left->next->next=head;
        left->next=right;
        return H.next;
    }
};
```
