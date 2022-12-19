```
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int n = 1;
        ListNode* last = head;
        ListNode* p = head;
        if(head == NULL)
            return NULL;
        while(last->next != NULL)
        {
            n++;
            last = last->next;
        }
        k %= n;
        if(k == 0)
            return head;
        k = n - k;
        while(k-- > 1)
        {
            p = p->next;
        }
        last->next = head;
        head = p->next;
        p->next = NULL;
        return head;
    }
};
```
