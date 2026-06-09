```cpp
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *p = dummy;
        while (p->next->val != val) {
            p = p->next;   
        }
        ListNode *tmp = p->next;
        p->next = tmp->next;
        // delete tmp;          // delete 原始数据就不能通过
        p = dummy->next;
        delete dummy;
        return p;
    }
};
```