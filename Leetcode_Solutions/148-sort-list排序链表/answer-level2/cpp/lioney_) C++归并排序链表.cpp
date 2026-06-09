```
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* pre = head, *slow = head, *fast = head;
        while(fast && fast->next) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = nullptr;
        return mergeTwoList(sortList(head), sortList(slow));
    }
    ListNode* mergeTwoList(ListNode* h1, ListNode* h2) {
        if(!h1) return h2;
        if(!h2) return h1;
        if(h1->val < h2->val) {
            h1->next = mergeTwoList(h1->next, h2);
            return h1;
        }
        else {
            h2->next = mergeTwoList(h1, h2->next);
            return h2;
        }
    }
};
```
