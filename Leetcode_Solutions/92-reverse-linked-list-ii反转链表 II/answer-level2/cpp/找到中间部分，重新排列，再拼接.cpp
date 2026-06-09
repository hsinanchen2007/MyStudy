```
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode nd(0), *pre, *cur, *last, *mid, *tmp;
        int i;
        pre = &nd;
        nd.next = head;
        for(i=1; i<m; i++)
        {
            pre = pre->next;
        }
        cur = pre->next;
        last = cur;
        mid = NULL;
        for(i=0; i<n-m+1; i++)
        {
            tmp = cur->next;
            cur->next = mid;
            mid = cur;
            cur = tmp;
        }
        last->next = cur;
        pre->next = mid;
        return nd.next;
    }
};
```
