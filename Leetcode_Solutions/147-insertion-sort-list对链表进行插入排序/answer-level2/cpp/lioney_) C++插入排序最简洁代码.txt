```
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode * dummy = new ListNode(-1), *cur = dummy;
        while(head) {
            ListNode* tmp = head->next;
            cur = dummy;
            while(cur->next && cur->next->val <= head->val) {
                cur = cur->next;
            }
            head->next = cur->next;
            cur->next = head;
            head = tmp;
        }
        return dummy->next;
    }
};
```
