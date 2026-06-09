```
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sign = 0;
        ListNode head(0);
        ListNode* cur = &head;
        while (l1 || l2 || sign) {
            int sum = (l1?l1->val:0) + (l2?l2->val:0) + sign;
            sign = sum / 10;
            ListNode* node = new ListNode(sum % 10);
            cur->next = node;
            cur = node;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        return head.next;
    }
};
```
