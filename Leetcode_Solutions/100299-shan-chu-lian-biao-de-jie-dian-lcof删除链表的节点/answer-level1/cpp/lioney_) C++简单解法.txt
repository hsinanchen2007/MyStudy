```
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if(head->val == val) {
            return head->next;
        }
        ListNode* p = head;
        while(p->next) {
            if(p->next->val == val) {
                ListNode * tmp = p->next;
                p->next = tmp->next;
                delete tmp;
                break;
            }
            p = p->next;
        }
        return head;
    }
};
```
