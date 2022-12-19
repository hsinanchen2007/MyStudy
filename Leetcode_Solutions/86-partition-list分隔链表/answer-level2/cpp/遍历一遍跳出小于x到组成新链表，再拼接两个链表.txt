```
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode n(0);
        ListNode f(0);
        ListNode* pre = &n, *last = &f;
        n.next = head;
        while(head != NULL)
        {
            if(head->val < x)
            {
                pre->next = head->next;
                head->next = NULL;
                last->next = head;
                last = head;
                head = pre->next;
            }
            else
            {
                pre = head;
                head = head->next;
            }
        }
        last->next = n.next;
        return f.next;
    }
};
```
