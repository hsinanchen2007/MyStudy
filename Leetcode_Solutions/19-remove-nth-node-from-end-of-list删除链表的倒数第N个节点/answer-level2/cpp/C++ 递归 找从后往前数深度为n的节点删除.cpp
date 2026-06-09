```
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dm = new ListNode(1);
        dm->next = head;
        helper(dm, head, n);
        return dm->next;
    }
    int helper(ListNode* front, ListNode* head, int n) {
        if (head == NULL) {
            return 0;
        }
        int now = 1 + helper(head, head->next, n);
        if (n == now) {
            front->next = head->next;
        }
        return now;
    }
};
```
